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
int n, m, a, b, c;
//vector<int> g[maxn]; 
ii li[1000];
ii li2[1000];
int main(){
	sc("%d\n", &n);
    for(int i = 0; i < n; i++) {
        sc("%d %d\n", &a, &b);
        li[i] = {a, b};
    }
    for(int i = 0; i < n; i++) {
        sc("%d %d\n", &a, &b);
        li2[i] = {-a, -b};
    }
    sort(li, li+n);
    sort(li2, li2+n);
    pr("%d %d\n",li[0].fi-li2[0].fi,  li[0].se-li2[0].se);
 	return 0;
}
