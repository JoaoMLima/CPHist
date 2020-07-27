#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 500007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int idTree[MAX];

int united[4*MAX];
int p[4*MAX];

int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}

void uni(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (rand()) p[a] = b;
		else p[b] = a;
	}
}

void build(int id, int l, int r) {
	p[id] = id;
	if (l == r) {
		idTree[l] = id;
		united[id] = 1;
		return;
	}
	int m = (l+r)/2;
	build(L(id), l, m);
	build(R(id), m+1, r);
}

void unite(int id, int l, int r, int i, int j, int v) {
	if (j < i || l > j || r < i) return;
	if (united[id]) {
		uni(id, idTree[v]);
		return;
	}
	if (l >= i && r <= j) {
		uni(id, idTree[v]);
		for(int k = l; k <= r; k++) {
			uni(id, idTree[k]);
		}
		united[id] = 1;
		return;
	}
	int m = (l+r)/2;
	unite(L(id), l, m, i, j, v);
	unite(R(id), m+1, r, i, j, v);
}

vector<int> g[MAX];
map<int, vector<int> > parents;

int main(){
	int n, m, a, b;
	sc("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	build(0, 1, n);
	for(int i = 1; i <= n; i++) {
		sort(g[i].begin(), g[i].end());
		int lst = 0;
		for (int x : g[i]) {
			unite(0, 1, n, lst+1, x-1, i);
			lst = x;
		}
		unite(0, 1, n, lst+1, n, i);
	}
	for(int i = 1; i <= n; i++) {
		parents[find(idTree[i])].pb(i);
	}
	pr("%d\n", sz(parents));
	for(pair<int, vector<int> > x : parents) {
		pr("%d", sz(x.se));
		for(int y : x.se) {
			pr(" %d", y);
		}pr("\n");
	}
 	return 0;
}