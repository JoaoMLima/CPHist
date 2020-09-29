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
typedef pair<ll, ll> ii;

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

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}


int crivo[1007];
int n;
string s;
vector<int> v;
int main(){
	sc("%d", &n);
	for(int i = 2; i < 1007; i++) {
		crivo[i] = 1;
	}
	for(int i = 2; i < 1007; i++) {
		if (crivo[i]) {
			for(int j = i*i; j < 1007; j += i) {
				crivo[j] = 0;
			}
			for(int j = i; j <= n; j *= i) {
				v.pb(j);
			}
		}
	}
	pr("%d\n", sz(v));
	for(int x : v) pr("%d ", x); pr("\n");
	
 	return 0;
}