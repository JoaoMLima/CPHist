#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;

int m, n, t, p, a, b, c;

ll modpow(ll a,ll b) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1LL)%MOD;
	ll r = modpow(a, b>>1);
	return r*r%MOD;
}

ll limitpow(ll a,ll b) {
	if (!b) return 1LL;
	if (b&1LL) return min(a*limitpow(a, b-1LL), 1000000LL);
	ll r = limitpow(a, b>>1);
	return min(r*r, 1000000LL);
}

ll grande(ll mul, ll a, ll b) {
	if (!mul) return 0;
	ll pw = limitpow(a, b);
	return min(mul*pw, 1000000LL);
}

int li[1000010];
int main(){
	sc("%d", &t);
	
	while(t--) {
		ll dif = 0;
		ll mdif = -1;
		sc("%d %d", &n, &p);
		
		for(int i = 0; i < n; i++) {
			sc("%d",li+i);
		}
		if (p == 1) {
			pr("%d\n", n%2);
			continue;
		}
		int botatudo = 0;
		sort(li, li+n);
		for(int i = n-1; i >= 0; i--) {
			if (i == n-1) {
				dif = 1;
			} else if (botatudo) {
				mdif = (mdif + MOD - modpow(p, li[i])) % MOD;
			} else {
				ll x = grande(dif, p, li[i+1]-li[i]);
				if (x >= 1000000LL) {
					mdif = ((dif % MOD) * modpow(p, li[i+1]))% MOD;
					botatudo = 1;
				} else {
					dif = x;
				}
				
				if (botatudo) {
					mdif = (mdif + MOD - modpow(p, li[i])) % MOD;
				} else {
					if (dif >= 1) dif--;
					else dif = 1LL;
				}
			}
		}
		if (mdif == -1LL) {
			mdif = ((dif % MOD) * modpow(p, li[0]))% MOD;
		}
		pr("%lld\n", mdif);
	}
 	return 0;
}