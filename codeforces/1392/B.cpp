#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}
ll li[200007];


int n, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		ll k;
		sc("%d %lld", &n, &k);
		ll maxi = -10000000000LL;
		ll mini = 10000000000LL;
		for(int i = 1; i <= n; i++) {
			sc("%lld", li+i);
			maxi = max(maxi, li[i]);
			mini = min(mini, li[i]);
		}
		for(int i = 1; i <= n; i++) {
			if (i > 1) pr(" ");
			pr("%lld", (k&1LL) ? maxi - li[i] : li[i]-mini);
		}pr("\n");
	}
 	return 0;
}
