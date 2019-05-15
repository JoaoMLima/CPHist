#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
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

//Trace dinamico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

//DP debug
int recNum = 0;
void prTabs() { range(recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}
int n, m, a, b, c;
int p[500001];
int sz[500001];
int find(int a) {
    //trace("p", a, p[a]);
    if (p[a] == a) return a;
    p[a] = find(p[a]);
    return p[a];
}
void Union(int a, int b) {
    a = find(a); b = find(b);
    //trace(a, b);
    if (a == b) return;
    if (rand() & 1) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}


int main(){
    for(int i = 0; i < 500001; i++) {
        sz[i] = 1;
        p[i] = i;
    }
	sc("%d %d", &n, &m);
    for(int i = 0; i < m; i++) {
        sc("%d", &b);
        int first;
        if (b != 0){
            sc("%d", &first);
        }
        for(int i = 1; i < b; i++) {
            sc("%d", &a);
            //trace("uni");
            Union(first, a);
        }
    }
    for(int i = 1; i <= n; i++) {
        pr("%d ", sz[find(i)]);
    }pr("\n");
 	return 0;
}
