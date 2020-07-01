#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c, r;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &r);
		ll x = min(r, n-1);
		ll total = ((1+x)*x)/2LL;
		if (r >= n) total++;

		pr("%lld\n", total);
	}
 	return 0;
}
