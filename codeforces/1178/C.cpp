#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
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
ll n, m, a, b, c;
ll expoMod(ll a, ll b, ll md) {
	if (!b) return 1LL;
	if (b & 1) return a * expoMod(a, b-1, md) % md;
	ll parcial = expoMod(a, b>>1, md);
	return parcial * parcial % md;
}
int main(){
	sc("%lld %lld", &n, &m);
	ll md = 998244353LL;
	ll resp = expoMod(2LL, n, md) * expoMod(2LL, m, md) % md;
	pr("%lld\n", resp);
 	return 0;
}
