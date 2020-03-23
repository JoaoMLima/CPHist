#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353LL

typedef long long ll;
typedef pair<int, int> ii;


ll t, n, m, k, a, b;
ll modpow(ll i) {
	if(i == 0) return 1LL;
	if (i & 1LL) return 10*modpow(i-1)%MOD;
	ll r = modpow(i >> 1);
	return r*r%MOD;
}

int main(){
	sc("%lld", &n);
	if (n == 1LL) {pr("10\n"); return 0;}
	if (n == 2LL) {pr("180 10\n"); return 0;}
	for(ll i = 1LL; i <= n; i++) {
		if (i > 1) pr(" ");
		if (i == n) {
			pr("10") % MOD;
			continue;
		}
		ll total = (2LL*10LL*9LL*modpow(n-i-1LL)) % MOD;
		if (n-2LL >= i) {
			total = (total + (n-2LL-i+1LL)*10LL*9LL*9LL*modpow(n-i-2LL))%MOD;
		}
		pr("%lld", total);
	}pr("\n");

 	return 0;
}
