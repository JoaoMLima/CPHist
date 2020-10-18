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

ll c[6];

int n, t, a, b;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &a, &b);
		for(int i = 0; i < 6; i++) {
			sc("%lld", c+i);
		}
		for(int i = 0; i < 36; i++) {
			for(int j = 0; j < 6; j++) {
				c[j] = min(c[j], c[(j+6-1)%6] + c[(j+1)%6]);
			}
		}
		//trace(c[0], c[1], c[2], c[3], c[4], c[5]);
		ll total = 0;
		if (a > 0 && b > 0) {
			int x = min(a, b);
			total += c[0]*x;
			a -= x;
			b -= x;
		}
		if (a < 0 && b < 0) {
			int x = min(abs(a), abs(b));
			total += c[3]*x;
			a += x;
			b += x;
		}
		if (a > 0) {
			total += c[5]*a;
		} else {
			total += c[2]*abs(a);
		}
		if (b > 0) {
			total += c[1]*b;
		} else {
			total += c[4]*abs(b);
		}
		pr("%lld\n", total);
	}
 	return 0;
}
