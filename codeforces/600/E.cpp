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
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

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
int c[MAX];
vector<int> g[MAX];
vector<pair<int, ii> > queries;
ll sumfreq[MAX];
int euler[MAX];
int freq[MAX];
ll resp[MAX];
int maxfreq = 0;
int pos = 1;
int root = 317;
void dfs(int v, int p = -1) {
	int lv = pos++;
	euler[lv] = c[v];
	for(int x : g[v]) {
		if (x == p) continue;
		dfs(x, v);
	}
	int rv = pos-1;
	queries.pb({v, mp(lv, rv)});
}

bool comp(pair<int, ii> a, pair<int, ii> b) {
	if (a.se.se / root != b.se.se / root) return a.se.se / root < b.se.se / root;
	return a.se.fi < b.se.fi;
}


int n, a, b;
int main(){
	sc("%d", &n);
	for(int i = 1; i <= n; i++) {
		sc("%d", c+i);
	}
	for(int i = 1; i < n; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(1);
	sort(queries.begin(), queries.end(), comp);
	int l = 1, r = 0;
	int L, R;
	for(pair<int, ii> q : queries) {
		L = q.se.fi, R = q.se.se;
		while(r < R) {
			int f = freq[euler[++r]];
			freq[euler[r]]++;
			if (maxfreq == f) maxfreq++;
			sumfreq[f] -= euler[r];
			sumfreq[f+1] += euler[r];
		}
		while(l > L) {
			int f = freq[euler[--l]];
			freq[euler[l]]++;
			if (maxfreq == f) maxfreq++;
			sumfreq[f] -= euler[l];
			sumfreq[f+1] += euler[l];
		}

		while(l < L) {
			int f = freq[euler[l]];
			freq[euler[l]]--;
			if (maxfreq == f && sumfreq[f] == euler[l]) maxfreq--;
			sumfreq[f] -= euler[l];
			sumfreq[f-1] += euler[l];
			l++;
		}

		while(r > R) {
			int f = freq[euler[r]];
			freq[euler[r]]--;
			if (maxfreq == f && sumfreq[f] == euler[r]) maxfreq--;
			sumfreq[f] -= euler[r];
			sumfreq[f-1] += euler[r];
			r--;
		}
		resp[q.fi] = sumfreq[maxfreq];
	}

	for(int i = 1; i <= n; i++) {
		if (i > 1) pr(" ");
		pr("%lld", resp[i]);
	}pr("\n");
 	return 0;
}
