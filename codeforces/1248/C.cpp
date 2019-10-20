#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mod 1000000007LL
 
typedef long long ll;
typedef pair<int, int> ii;
 
ll fact[100010];
ll invfact[100010];

ll modPow(ll a, ll b) {
	if(b == 0LL) return 1LL;
	if (b&1) return ((a*modPow(a, b-1)%mod)+mod)%mod;
	ll s = modPow(a, b>>1);
	return ((s*s%mod)+mod)%mod;
}
ll comb(ll n, ll k) {
	if(n-k == 0LL || k == 0LL) return 1LL;
	return ((fact[n]*invfact[k]%mod*invfact[n-k]%mod)+mod)%mod;
}

ll a, b;

int main(){
	ll n, m, t;
	fact[0] = 1LL;
	invfact[0] = 1LL;
	for(ll i = 1; i <= 100007; i++) {
		fact[i] = (((fact[i-1]*i)%mod)+mod)%mod;
	}

	for(ll i = 1; i <= 100007; i++) {
		invfact[i] = modPow(fact[i], mod-2LL);
	}

	sc("%lld %lld", &n, &m);

	vector<ll> res;
	ll resp = 0LL;
	for(ll i = 0; i <= n; i++) {
		if(i*2 <= n) {
			resp += comb(i+(n-(i*2)), i)*2;
		}
	}

	for(ll i = 0; i <= m; i++) {
		if(i*2 <= m) {
			resp += comb(i+(m-(i*2)), i)*2;
		}
	}

	resp -= 2;

	pr("%lld\n", resp%mod);

	return 0;
}