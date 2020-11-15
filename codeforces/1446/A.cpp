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
#define EPS 1e-12
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

pair<ll, int> li[2*MAX];
vector<int> resp;

int n, t; ll w,  a, b, c;
int main(){
    sc("%d", &t);
	while(t--) {
		resp.clear();
		sc("%d %lld", &n, &w);
		int best = -1;
		ll tet = w/2LL + (w%2LL);
		for(int i = 1; i <= n; i++) {
			sc("%lld", &a);
			if (a >= tet && a <= w) {
				best = i;
			}
			li[i] = {a, i};
		}
		if (best != -1) {
			pr("1\n%d\n", best);
			continue;
		}
		ll accum = 0LL;
		sort(li+1, li+n+1);
		for(int i = 1; i <= n; i++) {
			accum += li[i].fi;
			if (accum > w) {
				pr("-1\n");
				break;
			}
			if (accum >= tet) {
				for(int j = 1; j <= i; j++) {
					resp.pb(li[j].se);
				}
				pr("%d\n", i);
				sort(resp.begin(), resp.end());
				for(int j = 0; j < i; j++) {
					if (j) pr(" ");
					pr("%d", resp[j]);
				}pr("\n");
				break;
			}
			if (i == n) {
				pr("-1\n");
			}
		}
	}

 	return 0;
}
