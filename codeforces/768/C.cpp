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
int n, m, a, b, c, at = 0, temp, falta;
//vector<int> g[maxn]; 
int l[2][1024];
int main(){
	sc("%d %d %d", &n, &b, &c);
    memset(l, 0, sizeof l);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        l[0][a]++; 
    }
    for(int i = 0; i < b; i++) {
        for(int j = 0; j < 1024; j++) {
            l[!at][j] = 0;
        }
        falta = 1;
        for(int j = 0; j < 1024; j++) {
            temp = (l[at][j]+falta)>>1;
            l[!at][j^c] += temp;
            l[!at][j] += l[at][j] - temp;
            falta ^= (l[at][j] & 1);
        }
        at ^= 1;
    }
    int i = 0;
    while(l[at][i] == 0) i++;
    int j = 1023;
    while(l[at][j] == 0) j--;
    pr("%d %d\n", j, i);
 	return 0;
}