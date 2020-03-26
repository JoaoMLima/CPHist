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

int n, a, b, c;
int main(){
	sc("%d", &n);
	vector<int> g;
	if (n%4 == 0) {
		for(int i = 1; i+i <= n; i += 2) {
			int l = i, r = n+1-i;
			g.pb(l);
			g.pb(r);
		}
	} else if (n%4 == 1) {
		for(int i = 1; i+i <= n-1; i += 2) {
			int l = i+1, r = (n-1)+2-i;
			g.pb(l);
			g.pb(r);
		}
		g.pb(1);
	} else if (n%4 == 2) {
		for(int i = 1; i+i <= n; i++) {
			int l = i, r = n+1-i;
			if (r-l == 1) {
				g.pb(r);
			} else if (i&1){
				g.pb(l);
				g.pb(r);
			}
		}
	} else {
		for(int i = 1; i+i <= n-1; i++) {
			int l = i+1, r = (n-1)+2-i;
			//pr("%d %d\n", l, r);
			if (r-l == 1) {
				g.pb(r);
			} else if (i&1){
				g.pb(l);
				g.pb(r);
			}
		}
	}
	ll v = 0;
	for(int x : g) {
		v = v + x;
	}

	pr("%lld\n",abs(v-((n+1LL)*n/2LL-v)));
	pr("%d", (int)g.size());
	for(int i = 0; i < (int)g.size(); i++) {
		pr(" %d", g[i]);
	}pr("\n");
 	return 0;
}
