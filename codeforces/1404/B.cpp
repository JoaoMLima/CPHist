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


vector<int> g[MAX];


int dfs(int v, int p, int obj) {
	int d = MAX;
	if (v == obj) return 0;
	for(int c : g[v]) {
		if(c != p) {
			d = min(d, dfs(c, v, obj)+1);
		}
	}
	return d;
}

ii dfs(int v, int p) {
	ii resp = {v, 0};
	for(int c : g[v]) {
		if(c != p) {
			ii temp = dfs(c, v);
			if (temp.se+1 > resp.se) {
				resp = {temp.fi, temp.se+1};
			}
		}
	}
	return resp;
}

int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		string s;
		int n, a, b, da, db, x, y;
		sc("%d %d %d %d %d", &n, &a, &b, &da, &db);
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 0; i < n-1; i++) {
			sc("%d %d", &x, &y);
			g[x].pb(y);
			g[y].pb(x);
		}
		int dist = dfs(a, -1, b);
		if(dist <= da) {
			pr("Alice\n");
			continue;
		}


		ii longe = dfs(1, -1);
		longe = dfs(longe.fi, -1);
		if(da*2 >= longe.se) {
			pr("Alice\n");
			continue;
		}
		if(db <= da*2) pr("Alice\n");
		else pr("Bob\n");
	}
 	return 0;
}
