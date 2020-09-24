#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 998244353
#define MODL 998244353LL
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
struct eve {
	int x, tip, id;
	eve(int _x = 0, int _t = 0, int _i = 0) {
		x = _x, tip = _t, id = _i;
	}
	bool operator < (eve o) const {
		if (x != o.x) return x < o.x;
		if (tip != o.tip) return tip < o.tip;
		return id < o.id;  
	}
};

eve li[6*MAX];
ll fact[3*MAX];
ll invfact[3*MAX];

ll comb(ll a, ll b) {
	if (b > a) return 0LL;
	return MDL(MDL(fact[a]*invfact[b])*invfact[a-b]);
}

int n, t, k, a, b, c;
int main(){
	fact[0] = 1;
	invfact[0] = 1;
	for(int i = 1; i < 3*MAX; i++) {
		fact[i] = MDL(fact[i-1]*i);
		invfact[i] = invmod(fact[i], MODL);
	}

	t = 1;
	while(t--) {
		sc("%d %d", &n, &k);
		for(int i = 0; i < n; i++) {
			sc("%d %d", &a, &b);
			li[2*i] = eve(a, 0, i); 
			li[2*i+1] = eve(b, 1, i);
		}
		sort(li, li+(2*n));
		ll resp = 0LL;
		int abertos = 0;
		for(int i = 0; i < 2*n; i++) {
			//trace(li[i].x, li[i].tip, li[i].id);
			if (li[i].tip == 0) {
				abertos++;
			} else {
				abertos--;
				//pr("%d %d\n", abertos, k-1);
				resp = MDL(resp + comb(abertos, k-1));
			}
		}
		pr("%lld\n", resp);
	}
 	return 0;
}
