#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 998244353
#define md(x) (x) % mod
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ll, int> li;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, vector<int> > piv;
il parent[17][100001];
int height[100001];
int ranks[100001];
vector<ii> g[100001];
vector<ii> g2[100001];
int recurNumber = 0;
ll dists[42][100001];
void recInit(int x, int y, int z) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "Rec(" << x << ", " << y << ", " << z << "):\n";
	recurNumber++;}
void recEnd(int x) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "-> " << x << "\n";
	recurNumber--;}
int find(int v) {
	while(parent[0][v].fi != v) {
		v = parent[0][v].fi;
	}
	return v;
	}
void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (ranks[a] > ranks[b])
		parent[0][b].fi = a;
	else
		parent[0][a].fi = b;
	if (ranks[a] == ranks[b])
		ranks[b]++;
	}
ll dist(int a, int b) {
	if (height[a] < height[b]) {
		swap(a, b);
	}
	ll d = 0ll;
	int dif = height[a] - height[b];
	int k = 16;
	//pr("d: %I64d\n", d);
	while(dif != 0) {
		int num = 1 << k;
		if (dif >= num) {
			dif -= num;
			d += parent[k][a].se;
			//pr("d1: %I64d\n", d);
			a = parent[k][a].fi;
		}
		k--;
	}
	if (a == b) {
		return d;
	}
	for(int i = 16; i >= 0 ; i--) {
		if(parent[i][a].fi != parent[i][b].fi) {
			d += parent[i][a].se + parent[i][b].se;
			a = parent[i][a].fi;
			b = parent[i][b].fi;
		}
	}
	d += parent[0][a].se + parent[0][b].se;
	return d;
}
int n, m, q, k, t, a, b, c, x, y, z, w;
int main() {
	sc("%d %d", &n, &m);
	for(int i = 1 ; i <= n; i++) {
		parent[0][i].fi = i;
		ranks[i] = 0;
	}
	vector<iii> edges;
	vector<iii> extras;
	for(int i = 0; i < m; i++) {
		sc("%d %d %d", &a, &b, &c);
		edges.pb(mp(c, mp(a, b)));
	}
	sort(edges.begin(), edges.end());
	int id = 0;
	vector<int> pts;
	while(id < m) {
		iii f = edges[id++];
		if (find(f.se.fi) != find(f.se.se)) {
			g[f.se.fi].pb(mp(f.se.se, f.fi));
			g[f.se.se].pb(mp(f.se.fi, f.fi));
			Union(f.se.fi, f.se.se);
		} else {
			pts.pb(f.se.fi); pts.pb(f.se.se);
			g2[f.se.fi].pb(mp(f.se.se, f.fi));
			g2[f.se.se].pb(mp(f.se.fi, f.fi));
		}
	}
	for(int i = 0; i < pts.size(); i++) {
		for(int j = 0; j < 100001; j++) {
			dists[i][j] = LLONG_MAX;
		}
	}
	int vi[100001];
	for(int i = 0; i < pts.size(); i++) {
		priority_queue<li, vector<li>, greater<li> > pq;
		pq.push(mp(0ll, pts[i]));
		dists[i][pts[i]] = 0ll;
		for(int j = 1; j <= n; j++) {
			vi[j] = 0;
		}
		int falta = n;
		while(!pq.empty() && falta) {
			li f = pq.top(); pq.pop();
			if(vi[f.se]) {
				continue;
			}
			falta--;
			vi[f.se] = 1;
			for(int j = 0; j < g[f.se].size(); j++) {
				ll all = g[f.se][j].se;
				if (f.fi + all < dists[i][g[f.se][j].fi]) {
					dists[i][g[f.se][j].fi] = f.fi + all;
					pq.push(mp(f.fi + all, g[f.se][j].fi));
				}
			}
			for(int j = 0; j < g2[f.se].size(); j++) {
				ll all = g2[f.se][j].se;
				if (f.fi + all < dists[i][g2[f.se][j].fi]) {
					dists[i][g2[f.se][j].fi] = f.fi + all;
					pq.push(mp(f.fi + all, g2[f.se][j].fi));
				}
			}
		}
	}
	stack<int> st;
	height[1] = 0;
	parent[0][1] = mp(0, 0ll);
	st.push(1);
	while(!st.empty()) {
		int f = st.top(); st.pop();
		for(int i = 0; i < g[f].size(); i++) {
			if (g[f][i].fi != parent[0][f].fi) {
				parent[0][g[f][i].fi] = mp(f, (ll)g[f][i].se);
				height[g[f][i].fi] = height[f]+1;
				st.push(g[f][i].fi);
			}
		}
	}
	for(int i = 1; i < 17; i++) {
		for(int j = 1; j <= n; j++) {
			parent[i][j] = mp(parent[i-1][parent[i-1][j].fi].fi, parent[i-1][parent[i-1][j].fi].se + parent[i-1][j].se);
		}
	}
	/*
	st.push(1);
	while(!st.empty()) {
		int f = st.top(); st.pop();
		for(int i = 0; i < g[f].size(); i++) {
			if (g[f][i].fi != parent[0][f].fi) {
				pr("%d<->%d %d\n", f, g[f][i].fi, g[f][i].se);
				st.push(g[f][i].fi);
			}
		}
	}
	pr("----------\n");
	int visited[n+1];
	for(int i = 1; i <= n ; i++) {
		visited[i] = 0;
	}
	for(int i = 1; i <= n ; i++) {
		if (!visited[i]) {st.push(i); visited[i] = 1;}
	while(!st.empty()) {
		int f = st.top(); st.pop();
		for(int i = 0; i < g2[f].size(); i++) {
			
			if (!visited[g2[f][i].fi]) {
				pr("%d<->%d %d\n", f, g2[f][i].fi, g2[f][i].se);
				st.push(g2[f][i].fi);
				visited[g2[f][i].fi] = 1;
			}
		}
	}
	}*/
	sc("%d", &q);
	
	for(int i = 0; i < q; i++) {
		sc("%d %d", &a, &b);
		priority_queue<li, vector<li>, greater<li> > pq;
		//set<int> s(pts.begin(), pts.end());
		pq.push(mp(0ll, a));
		for(int j = 0; j < pts.size(); j++) {
			pq.push(mp(dists[j][a], pts[j]));
		}
		while(pq.top().se != b) {
			//pr("%I64d a\n", pq.top().fi);
			li f = pq.top(); pq.pop();
			//s.erase(f.se);
			//pr("%I64d c\n", f.fi + dist(f.se, b));
			pq.push(mp(f.fi + dist(f.se, b), b));
		}
		pr("%I64d\n", pq.top().fi);
	}
}