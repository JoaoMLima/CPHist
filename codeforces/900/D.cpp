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

ll modpow(ll e) {
	if (!e) return 1LL;
	if (e & 1LL) return 2LL*modpow(e-1)%MOD;
	ll r = modpow(e/2);
	return r*r%MOD;
}
int n;
vector<ll> divisors;
vector<ll> dpt;

ll x, y;

ll dp(int i) {
	if (dpt[i] == -1LL) {
		dpt[i] = modpow(divisors[i]-1LL);
		for(int j = 0; j < n; j++) {
			if (i != j && divisors[i]%divisors[j] == 0) {
				dpt[i] = (dpt[i]-dp(j)+MOD)%MOD;
			}
		}
	}
	return dpt[i];
}

int main(){
	sc("%lld %lld", &x, &y);
	if (y%x) {pr("0\n"); return 0;}
	ll r = modpow(y-1);
	y /= x;
	
	
	for(ll i = 2; i*i <= y; i++) {
		if (y%i == 0) {
			divisors.pb(i);
			dpt.pb(-1LL);
			if (i*i != y) {
				divisors.pb(y/i);
				dpt.pb(-1LL);
			}
		}
	}
	divisors.pb(1);
	dpt.pb(-1LL);
	if (y != 1LL) {
		divisors.pb(y);
		dpt.pb(-1LL);
	}
	n = (int)divisors.size();
	/*
	for(int i = 0; i < n; i++) {
		pr("%lld: %lld\n", divisors[i], dp(i));
	}
	*/
	pr("%lld\n", dp(n-1));

 	return 0;
}
