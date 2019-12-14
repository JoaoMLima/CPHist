#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
struct Dom {
	int n;
	vector<vi> e, re, g;
	vi id, p, sdom, dom, dsu, best, chd;
	vector<vi> bucket;
	int dtime = 0;

	Dom() {}
	Dom(int n) : n(n), e(n), re(n), g(n), id(n, -1), p(n), sdom(n), dom(n), dsu(n), best(n), bucket(n), chd(n) {}

	void find(int v) {
		if (v != dsu[v]) {
			find(dsu[v]);
			if (sdom[best[dsu[v]]] <= sdom[best[v]]) {
				best[v] = best[dsu[v]];
			}
			dsu[v] = dsu[dsu[v]];
		}
	}

	void dfs1(int v) {
		id[v] = dtime++;
		for(int to: e[v]) {
			if (id[to] == -1) {
				dfs1(to);
				p[id[to]] = id[v];
			}
			re[id[to]].pb(id[v]);
		}
	}

	void prt(int rt) {
		for(int v = 0; v < n; v++) {
			pr("%d (%d)", v, chd[v]);
			pr((v == rt) ? "(root):" : ":");
			for(int to: g[v]) {
				pr(" %d", to);
			}pr("\n");
		}
		pr("\n");
		
	}

	int dfs2(int v) {
		//pr("%d\n", v);
		for(int to: g[v]) {
			if (to != v) {
				chd[v] += dfs2(to);
			}
			
		}
		return chd[v];
	}

	void pre(int root) {
		dfs1(root);
		//fils array from l to r with 0,1,2,3....n
		//iota(left iterator, right iterator, initial value);
		iota(best.begin(), best.end(), 0);
		iota(sdom.begin(), sdom.end(), 0);
		for(int i = 0; i < n; i++) {
			chd[i] = 1;
		}
		iota(dsu.begin(), dsu.end(), 0);
	}

	void run(int root) {
		pre(root);//pr("root: %d\n", root);
		for(int v = n-1; v >= 0; v--) {
			for(int w: bucket[v]) {
				find(w);
				dom[w] = best[w];
			}
			for(int u: re[v]) {
				find(u);
				sdom[v] = min(sdom[v], sdom[best[u]]);
			}
			if (v){
				bucket[sdom[v]].pb(v);
				dsu[v] = p[v];
			}
		}

		for (int v = 1; v < n; v++) {
			if (dom[v] != sdom[v]) {
				dom[v] = dom[dom[v]];
			}
		}
		vi ndom(n), rev(n);

		for(int i = 0; i < n; i++) rev[id[i]] = i;
		for(int i = 0; i < n; i++) ndom[i] = rev[dom[id[i]]];
		dom = ndom;
		
		for(int i = 0; i < n; i++) {
			g[dom[i]].pb(i);
		}
		dfs2(root);
		//prt(root);
	}
};


int n, m, t, a, b, o, p;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d %d", &n, &m, &a, &b);
		Dom d1(n);
		Dom d2(n);
		for(int i = 0; i < m; i++) {
			sc("%d %d", &o, &p);
			d1.e[o-1].pb(p-1);
			d1.e[p-1].pb(o-1);
			d2.e[o-1].pb(p-1);
			d2.e[p-1].pb(o-1);
		}
		//pr("%d %d\n", a-1, b-1);
		d1.run(a-1);
		
		ll r = d1.chd[b-1]-1;
		d2.run(b-1);
		r *= d2.chd[a-1]-1;
		pr("%lld\n", r);
	}
 	return 0;
}
