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

int n, t, a, b, c, x, m;

int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d", &n, &x, &m);
		vector<ii> v;
		v.pb({x, x});
		for(int i = 0; i < m; i++) {
			int l, r;
			sc("%d %d", &l, &r);
			vector<ii> v2;
			int col = 0;
			int ok = 0;
			for(ii x : v) {
				if (!(x.fi > r || x.se < l)) {
					l = min(l, x.fi);
					r = max(r, x.se);
					ok = 1;
				} else if (x.se < l) {
					v2.pb(x);
				} else {
					if (!col && ok) v2.pb({l , r});
					v2.pb(x);
					col = 1;
				}
			}
			if(!col && ok) {
				v2.pb({l , r});
			}
			v = v2;
		}
		int re = 0;
		for(ii x : v) {
			re += x.se-x.fi+1;
			//pr("%d %d\n", x.fi, x.se);
		}
		pr("%d\n", re);
	}
	
 	return 0;
}
