#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

ll n, p;
int main(){
	sc("%lld %lld", &n, &p);
	ll ps = 1000000000000000000LL;
	for(ll i = 1; i < 50LL; i++) {
		ll s = i*p;
		ll f = n-s;
		ll cpf = f;
		if (f <= 0) {
			continue;
		}
		ll mini = 0LL;
		ll maxi = cpf;
		while(cpf) {
			cpf -= cpf&(-cpf);
			mini++;
		}
		if(i >= mini && i <= maxi) {
			ps = min(ps, i);
		}
	}
	if(ps == 1000000000000000000LL) pr("-1\n");
	else pr("%lld\n", ps);
 	return 0;
}
