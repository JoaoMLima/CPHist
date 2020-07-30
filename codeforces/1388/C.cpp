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

ll p[MAX]; //cidadaos
ll h[MAX]; //happiness
vector<int> g[MAX];

int dfs(int v, int par) {
	ll acch = 0;
	ll accp = 0;
	for(int x : g[v]) {
		if (x == par) continue;
		if (!dfs(x, v))return 0;
		acch += h[x];
		accp += p[x];
		//if (v == 1) pr("v: %d x: %d p: %lld h: %lld\n", v, x, p[x], h[x]);
		
	}
	//pr("v: %d accp: %lld acch: %lld\n", v, accp, acch);
	ll b = (accp+acch)/2 - acch;
	if (acch > h[v]) {
		ll dif = acch-h[v];
		if (dif > p[v] || (p[v]-dif)%2 != 0) {
			//pr("1 v: %d acch: %lld dif: %lld\n", v, acch, dif);
			return 0;
		}
	} else {
		ll dif = h[v]-acch;
		//pr("2 dif: %lld\n", dif);
		ll x = (dif / 2) * 2;
		//pr("2 accp: %lld acch: %lld b: %lld\n", accp, acch, b);
		x = min(x, b*2);
		//pr("2 x: %lld\n", x);
		dif -= x;
		//pr("2 dif: %lld\n", dif);
		if (dif > p[v] || (p[v]-dif)%2 != 0) {
			//pr("2 v: %d acch: %lld dif: %lld\n", v, acch, dif);
			return 0;
		}
	}
	p[v] += accp;
	return 1;
}


int t, a, b, c;
int main(){
	sc("%d", &t);
	//6 10 14 //15
	while(t--) {
		int n, m;
		sc("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			sc("%lld", p+i);
			g[i].clear();
		}
		for(int i = 1; i <= n; i++) {
			sc("%lld", h+i);
		}
		for(int i = 0; i < n-1; i++) {
			sc("%d %d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		if (dfs(1, -1)) pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
