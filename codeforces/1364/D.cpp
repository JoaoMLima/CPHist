#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int n, m, k, a, b, c, x, s;
vector<int> g[200007];
int nxt[200007];
int h[200007];
int p[200007];
int par[200007];
int qtdpa[2];
int bestciclo = -1;
int width;
void dfsciclo(int v) {

	for(int x: g[v]) {
		if (x == p[v]) continue;
		if (h[x] == -1) {
			p[x] = v;
			h[x] = h[v]+1;
			dfsciclo(x);
		} else if (h[x] < h[v]) {
			int sz = h[v]-h[x]+1;
			if (sz < width) {
				width = sz;
				bestciclo = v;
			}
		}
	}
}

void dfsparticiona(int v, int pa) {
	par[v] = pa;
	qtdpa[pa]++;
	for(int x: g[v]) {
		if (x == p[v]) continue;
		p[x] = v;
		dfsparticiona(x, !pa);
	}
}

int main(){
	sc("%d %d %d", &n, &m, &k);
	width = n+2;
	for(int i = 1; i <= n; i++) {
		h[i] = -1;
		par[i] = -1;
	}
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	if (m == n-1) {
		dfsparticiona(1, 0);
		int pa = 0;
		if (qtdpa[1] > qtdpa[0]) pa = 1;
		int qt = (k/2) + (k%2);
		int prti = 0;
		//pr("qt: %d pa: %d\n", qt, pa);
		pr("1\n");
		for(int i = 1; i <= n; i++) {
			//pr("par: %d\n", par[i]);
			if (par[i] == pa && qt) {
				if (prti) pr(" ");
				pr("%d", i);
				prti = 1;
				qt--;
			}
		}pr("\n");
	} else {
		h[1] = 0;
		dfsciclo(1);
		//pr("width: %d\n", width);
		if(width <= k) {
			pr("2\n");
			pr("%d\n", width);
			for(int i = 0; i < width; i++) {
				if (i) pr(" ");
				pr("%d", bestciclo);
				bestciclo = p[bestciclo];
			}pr("\n");
		} else {
			pr("1\n");
			int qt = (k/2) + (k%2);
			for(int i = 0; i < qt; i++) {
				if (i) pr(" ");
				pr("%d", bestciclo);
				bestciclo = p[bestciclo];
				bestciclo = p[bestciclo];
			}pr("\n");
		}
	}
	
 	return 0;
}
