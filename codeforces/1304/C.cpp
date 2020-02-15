#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
ll a, b, c;
int main(){
	int q;
	sc("%d", &q);
	while(q--) {
		ll n, m;
		sc("%lld %lld", &n, &m);
		ll mp = m&1LL;
		map<ll, ii> ma;
		ll ok = 1;
		for(ll i = 0; i < n; i++) {
			sc("%lld %lld %lld", &a, &b, &c);
			if (ma.count(a)) {
				ma[a].fi = max(ma[a].fi, b);
				ma[a].se = min(ma[a].se, c);
			} else {
				ma[a] = {b, c};
			}
		}
		ll antt = 0;
		ll antl = m, antr = m;
		for(pair<ll, ii> p : ma) {
			ll dif = p.fi-antt;
			ll mini = antl-dif, maxi = antr+dif;
			mini = max(mini, p.se.fi), maxi = min(maxi, p.se.se);
			if (mini > maxi) {
				ok = 0LL; break;
			}
			antl = mini, antr = maxi;
			antt = p.first;
		}
		if (ok == 0LL) {
			pr("NO\n");
		} else {
			pr("YES\n");
		}

	}
 	return 0;
}
