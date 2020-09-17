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
#define EPS 1e-12
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

vector<ll> neg;
vector<ll> pos;
int n, t; ll a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d\n", &n);
		ll resp = LLONG_MIN;
		neg.clear();
		pos.clear();
		for(int i = 0; i < n; i++) {
			sc("%lld", &a);
			if (a < 0) {
				neg.pb(a);
			} else {
				pos.pb(a);
			}
		}
		sort(neg.begin(), neg.end(), greater<ll>());
		sort(pos.begin(), pos.end());
		

		//maior negativo
		for(int i = 1; i <= min(5, sz(neg)); i+= 2) {
			ll r = 1LL;
			for(int j = 0; j < i; j++) {
				r *= neg[j];
			}
			if (sz(pos) < 5-i) continue;
			for(int j = 0; j < 5-i; j++) {
				r *= pos[j];
			}
			resp = max(resp, r);
		}
		//trace("res", resp);

		//zero
		if (sz(pos) > 0 && pos[0] == 0) {
			resp = 0;
		}
		sort(neg.begin(), neg.end());
		sort(pos.begin(), pos.end(), greater<ll>());
		//maior positivo
		//trace("res", resp);
		for(int i = 0; i <= min(5, sz(neg)); i+= 2) {
			ll r = 1LL;
			for(int j = 0; j < i; j++) {
				r *= neg[j];
			}
			if (sz(pos) < 5-i) continue;
			for(int j = 0; j < 5-i; j++) {
				r *= pos[j];
			}
			resp = max(resp, r);
		}

		//trace("res", resp);



		pr("%lld\n", resp);

	}
 	return 0;
}
