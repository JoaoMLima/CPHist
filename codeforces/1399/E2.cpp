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


priority_queue<pair<ll, pair<ll, int> > > pq[2];
vector<ll> cortes[2];
ll s0 = 0, s1 = 0;
vector<pair<int, ll> > g[2][MAX];
int dfs(int v, int p = -1) {
	int subtree = 0;
	for(pair<int, ll> x : g[0][v]) {
		if (x.fi == p) continue;
		int y = dfs(x.fi, v);
		pq[0].push(mp(x.se*y - (x.se/2)*y, mp(x.se, y)));
		s0 += x.se*y;
		subtree += y;
	}
	for(pair<int, ll> x : g[1][v]) {
		if (x.fi == p) continue;
		int y = dfs(x.fi, v);
		pq[1].push(mp(x.se*y - (x.se/2)*y, mp(x.se, y)));
		s1 += x.se*y;
		subtree += y;
	}
	if (subtree == 0) subtree++;
	return subtree;
}

int n, t, a, b, c;
ll s, w;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %lld", &n, &s);
		s0 = 0, s1 = 0;
		while(!pq[0].empty()) pq[0].pop();
		while(!pq[1].empty()) pq[1].pop();
		cortes[0].clear();cortes[1].clear();
		pq[0].push(mp(0, mp(0, 0)));pq[1].push(mp(0, mp(0, 0)));
		for(int i = 1; i <= n; i++) {
			g[0][i].clear();
			g[1][i].clear();
		}
		for(int i = 0; i < n-1; i++) {
			sc("%d %d %lld %d", &a, &b, &w, &c);
			g[c-1][a].pb({b, w});
			g[c-1][b].pb({a, w});
		}
		dfs(1);
		cortes[0].pb(s0);
		while(pq[0].top().fi != 0) {
			pair<ll, pair<ll, int> > x = pq[0].top();pq[0].pop();
			//trace("top 1:", x, s0+(x/2)-x);
			s0 -= x.fi;
			ll newedge = x.se.fi/2;
			ll qtd = x.se.se;
			pq[0].push(mp(newedge*qtd - (newedge/2)*qtd, mp(newedge, qtd)));
			cortes[0].pb(s0);
		}
		cortes[1].pb(s1);
		while(pq[1].top().fi != 0) {
			pair<ll, pair<ll, int> > x = pq[1].top();pq[1].pop();
			s1 -= x.fi;
			ll newedge = x.se.fi/2;
			ll qtd = x.se.se;
			pq[1].push(mp(newedge*qtd - (newedge/2)*qtd, mp(newedge, qtd)));
			cortes[1].pb(s1);
		}
		int best = 1000000000;
		int j = sz(cortes[1])-1;
		for(int i = 0; i < sz(cortes[0]); i++) {
			if (cortes[0][i] > s) continue;
			while(j >= 0 && cortes[0][i] + cortes[1][j] <= s) j--;
			//trace("i:", i, "j:", j+1, "r:", i+2*(j+1));
			best = min(best, i+2*(j+1));
		}
		pr("%d\n", best);
	}

 	return 0;
}
