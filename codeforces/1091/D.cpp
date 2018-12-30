#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 998244353LL
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
ll fact[1000010];
ll invfact[1000010];

int main(){
    fact[0] = 1LL;
    for(ll i = 1; i < 1000010; i++) {
        fact[i] = md(fact[i-1]*i);
    }
    invfact[1] = 1LL;
    for (ll i=2; i<1000010; i++) {
        invfact[(int)i] = md( - (mod / i) * invfact[(int)(mod % i)]);
    }
    for (int i=2; i<1000010; i++) {
        invfact[i] = md(invfact[i-1]*invfact[i]);
    }
    sc("%d\n", &n);
    ll s = fact[n];
    for(int i = 1; i < n; i++) {
        s = md(s + md(md(fact[n]*invfact[n-i])*(fact[n-i]-1LL)));
    }
    pr("%lld\n", s);
    return 0;
}
