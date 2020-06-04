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

int m, n, a, b, c;
int val[500010];
vector<int> g[500010];
int main(){
	sc("%d %d", &n, &m);
	vector<ii> v;

	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	for(int i = 1; i <= n; i++) {
		sc("%d", &a);
		v.pb({a, i});
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++) {
		int mx = v[i].fi;
		//cout << "mx: " << mx << endl;
		//cout << "tam: " << g[v[i].se].size() << endl;
		if (g[v[i].se].size() < mx-1) {
			pr("-1\n");
			return 0;
		}
		
		vector<int> mxv;
		mxv.pb(1);
		for(int i = 1; i <= mx; i++) {
			mxv.pb(1);
		}
		for(int x : g[v[i].se]) {
			if (val[x] != 0 && val[x] <= mx) {
				mxv[val[x]] = 0;
			}
		}
		for(int i = 1; i < mx; i++) {
			if (mxv[i]) {
				pr("-1\n");
				return 0;
			}
		}
		if (!mxv[mx]) {
			pr("-1\n");
			return 0;
		}
		val[v[i].se] = mx;
	}
	for(int i = 0; i < n; i++) {
		if (i) pr(" ");
		pr("%d", v[i].se);
	}pr("\n");
 	return 0;
}
