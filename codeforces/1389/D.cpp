#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
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

ll inic[MAX];

int t;
int main(){
	sc("%d\n", &t);
	while(t--) {
		ll n, k, a, b, x, y;
		sc("%lld %lld", &n, &k);
		sc("%lld %lld", &a, &b);
		sc("%lld %lld", &x, &y);
		ll c, g, d; //custo juntar //qtdgratis //disponivel de 1 em 1
		if (x < a) {
			swap(a, x);
			swap(b, y);
		}
		ll il = max(a, x), ir = min(b, y);
		if (il <= ir) {
			c = 0;
			g = ir-il;
			d = abs(a-x)+abs(b-y);
			k -= g*n;
			ll r = 0;
			if (k <= 0) pr("%lld\n", r);
			else {
				ll mi = min(k, d*n);
				r += mi;
				k -= mi;
				if (k <= 0) pr("%lld\n", r);
				else pr("%lld\n", r+2LL*k);
			}
			continue;
		}
		c = x-b;
		g = 0;
		d = max(b, y)-min(a, x);
		inic[1] = 1;
		for(int i = 2; i <= n; i++) {
			ll re = 1000000000000000007LL;
			ll l = inic[i-1], r = 1000000000000000007LL;
			while(l <= r) {
				ll mid = (l+r)/2LL;
				ll mi1 = min(mid, d*i);
				ll mi2 = min(mid, d*(i-1));
				ll c1 = c*i + mi1 + (mid-mi1)*2LL;
				ll c2 = c*(i-1) + mi2 + (mid-mi2)*2LL;
				if (c1 < c2) {
					re = mid;
					r = mid-1LL;
				} else {
					l = mid+1;
				}
			}
			inic[i] = re;
		}
		ll best = 1;
		for(int i = 1; i <= n; i++) {
			if (inic[i] <= k) best = i;
		}
		
		ll mi1 = min(k, d*best);
		ll c1 = c*best + mi1 + (k-mi1)*2LL;
		pr("%lld\n", c1);
	}
 	return 0;
}
