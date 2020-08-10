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
string s;
// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; //cin >> s;
}
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

ll fact[1000007];
ll invfact[1000007];

ll comb(int a, int b) {
	return MDL(MDL(fact[a]*invfact[b])*invfact[a-b]);
}

vector<int> g[500007];
vector<int> h[500007];

int best[500007];
int vbest[500007];
int vi[500007];
vector<ii> resp;

int dfs(int v, int he) {
	//trace(v, p, he);
	h[he].pb(v);
	vbest[v] = v;
	best[v] = 0;
	//trace("v:",v);
	for(int x : g[v]) {
		if (vi[x]) continue;
		//trace("x:",x,he+1);
		vi[x] = 1;
		int tmph = 1 + dfs(x, he+1);
		if (tmph > best[v]) {
			best[v] = tmph;
			vbest[v] = x;
		}
	}
	//trace(v, best[v].fi, best[v].se);
	return best[v];
}

int n, m, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &m);
		resp.clear();
		for(int i = 0; i <= n; i++) {
			h[i].clear();
			g[i].clear();
			vi[i] = 0;
		}
		for(int i = 0; i < m; i++) {
			sc("%d %d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		vi[1] = 1;
		//trace("aqui");
		dfs(1, 0);
		int qtd = (n/2) + (n%2);
		//trace(n, qtd);
		int ok = 0;
		if (best[1] >= qtd-1) {
			//trace("aqui2");
			int v = 1;
			pr("PATH\n");
			pr("%d\n", best[1]+1);
			pr("1");
			while(vbest[v] != v) {
				//trace("v", v);
				pr(" %d", vbest[v]);
				v = vbest[v];
			}pr("\n");
			continue;
		}
		//trace("aqui3");
		pr("PAIRING\n");
		for(int i = 0; i < n; i++) {
			for(int j = 1; j < sz(h[i]); j += 2) {
				resp.pb({h[i][j-1], h[i][j]});
			}
		}
		pr("%d\n", sz(resp));
		for(ii x : resp) {
			pr("%d %d\n", x.fi, x.se);
		}
	}
 	return 0;
}