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

int a, b, c;
int main(){
	int t;
	sc("%d", &t);
	ll n, k;
	while(t--) {
		sc("%lld %lld", &n, &k);
		ll r = 2;
		for(ll i = 2; i <= n; i++) {
			if (n % i == 0) {
				r = i;
				break;
			}
		}
		r += n;
		k--;
		r += (k*2);
		pr("%lld\n", r);
	}
 	return 0;
}
