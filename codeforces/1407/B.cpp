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


int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		vector<int> v;
		vector<int> r;
		int g = 0;
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			v.pb(a);
		}
		int maior = 0;
		for(int i = 0; i < n; i++) {
			if (v[i] > v[maior]) maior = i;
		}
		r.pb(v[maior]);
		g = v[maior];
		v.erase(v.begin()+maior);
		while(!v.empty()) {
			int maior = 0;
			for(int i = 0; i < sz(v); i++) {
				if (__gcd(v[i], g) > __gcd(v[maior], g)) {
					maior = i;
				}
			}
			r.pb(v[maior]);
			g = __gcd(v[maior], g);
			v.erase(v.begin()+maior);
		}
		for (int i = 0; i < sz(r); i++) {
			if (i) pr(" ");
			pr("%d", r[i]);
		}pr("\n");
	}
 	return 0;
}
