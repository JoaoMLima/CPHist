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

struct pt {
	int l, r;
};

struct chain {
	pt l, r;
};

struct cycle {
	pt l, m, r;
};

int nxt[MAX];
int vi[MAX];
vector<int> g[MAX];
vector<int> recur;
vector<int> seq;
vector<pt> pts;
vector<chain> chains;
vector<chain> chains2;
vector<cycle> cycles;
vector<cycle> cycles2;

int isChain(int v, int p = -1) {
	vi[v] = 1;
	if (g[v].size() == 0) return -1;
	if (g[v].size() == 1) return v;
	if (sz(recur) && v == recur[0]) return 0;
	recur.pb(v);
	if (g[v][0] == p) {
		return isChain(g[v][1], v);
	}
	return isChain(g[v][0], v);
}

void markCycle(int v, int p = -1) {
	vi[v] = 1;
	if (sz(recur) && v == recur[0]) return;
	recur.pb(v);
	if (g[v][0] == p) {
		markCycle(g[v][1], v);
		return;
	}
	markCycle(g[v][0], v);
}

void markChain(int v, int p = -1) {
	vi[v] = 1;
	recur.pb(v);
	//cout << "chain " << v << " " << p << endl;
	if (sz(recur) > 1 && sz(g[v]) == 1) {return;}
	if (p != -1 && g[v][0] == p) {
		markChain(g[v][1], v);
		return;
	}
	markChain(g[v][0], v);
}

int t;
int main(){
	int n, m, a, b;
	sc("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 1; i <= n; i++) {
		if (!vi[i]) {
			recur.clear();
			//cout << "procura " << i << endl;
			int c = isChain(i);
			//cout << "achou "<< c << endl;
			recur.clear();
			if (c == -1) {
				pts.pb({i, i});
			} else if (c == 0) {
				//cout << "cycle! " << endl;
				markCycle(i);
				//cout << "size: " << sz(recur) << endl;
				if (sz(recur) == 3) {
					pt l = {recur[0], recur[0]};
					pt m = {recur[1], recur[1]};
					pt r = {recur[2], recur[2]};
					cycles.pb({l, m, r});
					//cout << "acabou 3! "<< endl;
				} else if (sz(recur) == 4) {
					nxt[recur[0]] = recur[2];
					nxt[recur[1]] = recur[3];
					pt l = {recur[0], recur[2]};
					pt m = {recur[1], recur[1]};
					pt r = {recur[3], recur[3]};
					cycles.pb({l, m, r});
					//cout << "acabou 4! "<< endl;
				} else {
					if (sz(recur) % 2 == 0) {
						seq.clear();
						for(int j = 0; j < sz(recur); j += 2) seq.pb(recur[j]);

						for(int j = 0; j < sz(seq); j++) nxt[seq[j]] = seq[(j+1)%sz(seq)];

						pt l = {seq[0], seq[sz(seq)-3]};
						pt m = {seq[sz(seq)-2], seq[sz(seq)-2]};
						pt r = {seq[sz(seq)-1], seq[sz(seq)-1]};
						cycles2.pb({l, m, r});

						seq.clear();
						for(int j = 1; j < sz(recur); j += 2) seq.pb(recur[j]);

						for(int j = 0; j < sz(seq); j++) nxt[seq[j]] = seq[(j+1)%sz(seq)];

						l = {seq[0], seq[sz(seq)-3]};
						m = {seq[sz(seq)-2], seq[sz(seq)-2]};
						r = {seq[sz(seq)-1], seq[sz(seq)-1]};
						cycles2.pb({l, m, r});
						//cout << "acabou par! "<< endl;
					} else {
						int qtdj = 0;
						seq.clear();
						for(int j = 0; j || !qtdj; j = (j + 2)%sz(recur)) {
							if (j == 0) qtdj++;
							seq.pb(recur[j]);
						}

						for(int j = 0; j < sz(seq); j++) nxt[seq[j]] = seq[(j+1)%sz(seq)];

						pt l = {seq[0], seq[sz(seq)-3]};
						pt m = {seq[sz(seq)-2], seq[sz(seq)-2]};
						pt r = {seq[sz(seq)-1], seq[sz(seq)-1]};
						cycles2.pb({l, m, r});
						//cout << "acabou impar! "<< endl;
					}
				}
			} else {
				//cout << "chain! " << endl;
				markChain(c);
				//cout << "size: " << sz(recur) << endl;
				if (sz(recur) == 2) {
					pt l = {recur[0], recur[0]};
					pt r = {recur[1], recur[1]};
					chains.pb({l, r});
					//cout << "acabou 2! "<< endl;
				} else if (sz(recur) == 3) {
					nxt[recur[0]] = recur[2];
					pt l = {recur[0], recur[2]};
					pt r = {recur[1], recur[1]};
					chains.pb({l, r});
					//cout << "acabou 3! " << endl;
				} else {
					seq.clear();
					for(i = (sz(recur)-1)/2; i >= 0; i--) seq.pb(recur[i*2]);
					
					for(i = sz(recur)/2; i >= 1; i--) seq.pb(recur[i*2-1]);
					
					for(int j = 0; j < sz(seq)-1; j ++) nxt[seq[j]] = seq[j+1];

					pt l = {seq[0], seq[sz(seq)-2]};
					pt r = {seq[sz(seq)-1], seq[sz(seq)-1]};
					chains2.pb({l, r});
					//cout << "acabou mais! " << endl;
				}
			}
		}
	}
/*
	for(int i = 1; i <= 8; i++) {
		cout << i << "\t";
	}cout << endl;

	for(int i = 1; i <= 8; i++) {
		cout << nxt[i] << "\t";
	}cout << endl;

	cout << "jaqui" << endl;
*/
	int ok = 1;
	while(!chains.empty()) {
		//cout << "chain" << endl;
		chain c = chains.back(); chains.pop_back();
		if (!chains.empty() || !chains2.empty()) {
			
			chain c2;
			if (!chains.empty()) {
				c2 = chains.back(); chains.pop_back();
			} else {
				c2 = chains2.back(); chains2.pop_back();
			}
			swap(c.r, c2.r);
			nxt[c.l.r] = c.r.l;
			nxt[c2.l.r] = c2.r.l;
			chains2.pb(c);
			chains2.pb(c2);
			continue;
		}
		if (!cycles.empty() || !cycles2.empty()) {
			cycle c2;
			if (!cycles.empty()) {
				c2 = cycles.back(); cycles.pop_back();
			} else {
				c2 = cycles2.back(); cycles2.pop_back();
			}

			nxt[c2.l.r] = c.l.l;
			nxt[c.l.r] = c2.m.l;
			nxt[c2.m.r] = c.r.l;
			nxt[c.r.r] = c2.r.l;
			c.l.l = c2.l.l;
			c.l.r = c.r.r;
			c.r = c2.r;
			chains2.pb(c);
			continue;
		}
		if (!pts.empty()) {
			pt p = pts.back(); pts.pop_back();
			c.r = p;
			nxt[c.l.r] = p.l;
			chains2.pb(c);
			continue;
		}
		pr("-1\n");
		return 0;
	}

	while(!cycles.empty()) {
		cycle c = cycles.back(); cycles.pop_back();
		if (!cycles.empty() || !cycles2.empty()) {
			
			cycle c2;
			if (!cycles.empty()) {
				c2 = cycles.back(); cycles.pop_back();
			} else {
				c2 = cycles2.back(); cycles2.pop_back();
			}

			nxt[c.l.r] = c2.l.l;
			nxt[c2.l.r] = c.m.l;
			nxt[c.m.r] = c2.m.l;
			nxt[c2.m.r] = c.r.l;
			nxt[c.r.r] = c2.r.l;
			nxt[c2.r.r] = c.l.l;

			c.l.r = c2.l.r;
			c.m.r = c2.m.r;
			c.r.r = c2.r.r;
			cycles2.pb(c);
			continue;
		}
		if (!chains.empty() || !chains2.empty()) {
			chain c2;
			if (!chains.empty()) {
				c2 = chains.back(); chains.pop_back();
			} else {
				c2 = chains2.back(); chains2.pop_back();
			}

			nxt[c.l.r] = c2.l.l;
			nxt[c2.l.r] = c.m.l;
			nxt[c.m.r] = c2.r.l;
			nxt[c2.r.r] = c.r.l;
			c2.l.l = c.l.l;
			c2.l.r = c2.r.r;
			c2.r = c.r;
			chains2.pb(c2);
			continue;
		}

		if (!pts.empty() && c.l.l != c.l.r) {
			pt p = pts.back(); pts.pop_back();
			nxt[c.l.r] = p.l;
			nxt[p.r] = c.m.l;
			nxt[c.m.r] = c.r.l;
			chain c2;
			c2.l.l = c.l.l;
			c2.l.r = c.m.r;
			c2.r = c.r;
			chains2.pb(c2);
			continue;
		}

		if (sz(pts) >= 2) {
			pt p1 = pts.back(); pts.pop_back();
			pt p2 = pts.back(); pts.pop_back();
			c.m = p1;
			c.r = p2;
			nxt[c.l.r] = c.m.l;
			nxt[c.m.r] = c.r.l;
			nxt[c.r.r] = c.l.l;
			cycles2.pb(c);
			continue;
		}
		pr("-1\n");
		return 0;
	}
/*
	for(int i = 1; i <= 8; i++) {
		cout << i << "\t";
	}cout << endl;

	for(int i = 1; i <= 8; i++) {
		cout << nxt[i] << "\t";
	}cout << endl;
*/
	for(chain c : chains2) {
		int i = c.l.l;
		int j = c.r.r;
		while(i != j) {
			//int a; cin >> a;
			pr("%d %d\n", i, nxt[i]);
			i = nxt[i];
		}
	}

	for(cycle c : cycles2) {
		int i = c.l.l;
		int j = c.l.l;
		while(1) {
			pr("%d %d\n", i, nxt[i]);
			i = nxt[i];
			if (i == j) break;
		}
	}

 	return 0;
}
