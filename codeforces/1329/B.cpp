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

int d, m;
ll dpt[42];

ll modpow(ll a, ll b) {
	if (!b)return 1LL;
	if (b&1LL) return a*modpow(a, b-1LL)%m;
	ll r = modpow(a, b>>1);
	return r*r%m;
}
ll dp(ll b, ll bt) {
	if (dpt[b] != -1LL) return dpt[b];
	if (bt) dpt[b] = (d-modpow(2, b)+1LL+m)%m;
	else dpt[b] = modpow(2, b);
	ll tmp = dpt[b];
	for(int i = 0; i < b; i++) {
		dpt[b] = (dpt[b] + (tmp*dp(i, 0)%m))%m;
	}
	return dpt[b];
}
int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		for(int i = 0; i < 42; i++) {
			dpt[i] = -1LL;
		}
		sc("%d %d\n", &d, &m);
		int b = 0;
		for(int i = 1; i < 40; i++) {
			if((1LL<<i) <= d) {
				b = i;
			}
		}
		//pr("%d\n", b);
		ll qt = 0LL;
		for(int i = 0; i <= b; i++) {
			if (i == b) qt = (qt+dp(i, 1))%m;
			else qt = (qt+dp(i, 0))%m;
			//pr("%d %lld\n", i, dp(i,0));
		}
		pr("%lld\n", qt);

	}
 	return 0;
}
