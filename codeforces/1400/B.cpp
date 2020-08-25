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



int t; ll p, f, s, w, cts, ctw, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld\n", &p, &f);
		sc("%lld %lld\n", &cts, &ctw);
		sc("%lld %lld\n", &s, &w);
		if (s > w) {
			swap(s, w);
			swap(cts, ctw);
		}
		ll l = 0, r = cts + ctw;
		ll resp = 0;
		while (l <= r) {
			ll m = (l+r)/2LL;
			int ok = 0;
			for(int i = 0; i <= min(m, cts); i++) {
				ll total = m;
				ll qts = i;
				ll ps = qts*s;
				if (ps <= p) {
					total -= qts;
					total -= (p-ps)/w;
					if (total > 0) {
						qts = min(cts-qts, total);
						ll qtw = total - qts;
						if (qts*s + qtw*w <= f) total = 0;
					}
				}
				if (total <= 0) {ok = 1;break;}
			}
			if(ok) {
				resp = m;
				l = m+1;
			} else {
				r = m-1;
			}
		}
		pr("%lld\n", resp);
	}
 	return 0;
}
