#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

ll n, a, b, c;
int main(){
	sc("%lld", &n);
	map<ll, ll> m;
	
	for(ll i = 2LL; i*i <= n; i++) {
		while(n % i == 0){n/= i;m[i]++;}
	}
	if(n != 1LL) {
		m[n]++;
	}
	if(m.size() == 1) {
		pr("%lld\n", m.begin()->first);
	} else {
		pr("1\n");
	}
 	return 0;
}
