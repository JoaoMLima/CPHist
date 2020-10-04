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
ll inv = invmod(2LL, MODL);
ll solve(ll i) {
	return MDL( MDL((i+1)*i) *inv);
}

vector<ll> v;
int n, t, a, b, c, m;
int main(){
	char ch = getchar();
	while(ch != '\n') {
		v.pb(ch-'0');
		ch = getchar();
	}
	n = sz(v);
	ll total = 0LL;
	ll sum = 0;
	ll pot = 1;
	ll mul = 1;
	ll qtd3 = 0;
	//trace("aqui");
	for(int i = n-2; i >= 0; i--) {
		sum = MDL(sum + MDL(pot*mul));
		//trace(v[i], MDL(v[i]*sum));
		total = MDL(total + MDL(v[i]*sum));
		pot = MDL(pot*10LL);
		mul++;
	}
	//trace("aqui");
	pot = 1;
	for(int i = n-1; i >= 0; i--) {
		//trace(v[i], MDL(MDL(v[i]*pot)*solve(i)));
		total = MDL(total + MDL(v[i]*pot)*solve(i));
		pot = MDL(pot*10LL);
	}
	pr("%lld\n", total);
 	return 0;
}
