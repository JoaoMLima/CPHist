#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, a, b, c;
int p[1<<22];
int ranki[1<<22];
int conecta[1<<22];
int li[1<<22];
int l[1<<22];

int find(int i) {
    if(p[i] == -1) return -1;
    if (p[i] == i) return i;
    return find(p[i]);
}
void Union(int a, int b) {
    int a1 = find(a);
    int b1 = find(b);
    p[a] = a1;
    p[b] = b1;
    if(a1 == b1) return;
    if (ranki[a1] > ranki[b1]) p[b1] = a1;
    else p[a1] = b1;
    if(ranki[a1] == ranki[b1]) ranki[b]++;
}



int main(){
    memset(ranki, 0, sizeof ranki);
    memset(p, -1, sizeof p);
    memset(l, 0, sizeof l);
    memset(conecta, -1, sizeof conecta);
	sc("%d %d\n", &n, &m);
    for(int i = 0; i < m; i++) {
        sc("%d", li+i);
        p[li[i]] = li[i];
        l[li[i]]++;
    }
    int mask = (1<<22)-1;
    for(int i = 0; i < m; i++) {
        conecta[(~(li[i]))&mask] = li[i];
    }
    
    for(int i = 0; i <= mask; i++) {
        int i2 = (~i)&mask;
        int bi = i2 & (-i2);
        while(i2){
            l[i ^ bi] += l[i];
            i2 -= bi;
            bi = i2 & (-i2);
        }
    }
    for(int i = mask; i >= 0; i--) {
        if(conecta[i] != -1 && l[i]) {
            if(p[i] != -1) {
                Union(i, conecta[i]);
            }
            int i2 = i;
            int bi = i2 & (-i2);
            while(i2) {
                if(l[i ^ bi]) {
                    if(conecta[i ^ bi] != -1) {
                        Union(conecta[i ^ bi], conecta[i]);
                    }
                    conecta[i ^ bi] = conecta[i];
                }
                i2 -= bi;
                bi = i2 & (-i2);
            }
        }
        
    }
    
    set<int> s;
    
    for(int i = 0; i <= mask; i++) {
        s.insert(find(i));
    }
    s.erase(-1);
    pr("%d\n", (int)s.size());
 	return 0;
}