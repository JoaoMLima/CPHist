#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int vi[200010];
int he[200010];
int p[18][200010];
vector<int> g[200010];
int n, m, a, b, t, k;

void dfs(int v) {
	vi[v] = 1;
	for(int x : g[v]) {
		if (!vi[x]) {
			he[x] = he[v]+1;
			p[0][x] = v;
			dfs(x);
		}
	}
}

void init() {
	for(int i = 1; i < 18; i++) {
		for(int j = 1; j <= n; j++) {
			p[i][j] = p[i-1][p[i-1][j]];
		}
	}
}

int lca(int u, int v) {
	if (he[u] > he[v]) return 0;
	int dif = he[v]-he[u];
	for(int i = 17; i >= 0; i--) {
		//pr("v: %d dif: %d\n", v, dif);
		if (dif >= (1 << i)) {
			dif -= (1 << i);
			v = p[i][v];
		}
	}
	return u == v;
}

bool comp(int x, int y) {
	return he[x] < he[y];
}



int main(){
	sc("%d %d", &n, &m);
	for(int i = 0; i < n-1; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	init();
	for(int i = 0; i < m; i++) {
		sc("%d", &k);
		vector<int> vt;
		for(int j = 0; j < k; j++) {
			sc("%d", &a);
			vt.pb(a);
		}
		int last = 1;
		int ok = 1;
		sort(vt.begin(), vt.end(), comp);
		for(int j = 0; j < k; j++) {
			//pr("vt[j]: %d last: %d\n", vt[j], last);
			if (vt[j] == last || p[0][vt[j]] == last) continue;
			if (!lca(last, vt[j])) {
				ok = 0;
				break;
			}
			last = p[0][vt[j]];
		}
		if (ok)pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
