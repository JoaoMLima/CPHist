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

int n, m, a, b;
int p[10010];
int c[10010];
vector<int> g[10010];
void dfs(int v, int pa) {
	p[v] = pa;
	for(int ch: g[v]) {
		if (ch != pa) dfs(ch, v);
	}
}
int main(){
	memset(p, -1, sizeof p);
	vector<ii> v;
	sc("%d", &n);
	for(int i = 2; i <= n; i++) {
		sc("%d", &a);
		g[i].pb(a);
		g[a].pb(i);
	}
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		sc("%d", &a);
		c[i] = a;
	}
	int r = 1;
	for(int i = 1; i <= n; i++) {
		if (c[i] != c[p[i]]) r++;
	}
	pr("%d\n", r);
	
 	return 0;
}
