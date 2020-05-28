#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010;

typedef long long ll;
typedef pair<int, int> ii;

int n; ll a, b, t, m;
int li[1010][1010];
int main(){
	sc("%d\n", &n);
	while(n--) {
		sc("%lld %lld %lld\n", &a, &b, &t);
		
		if (2LL*t <= a+b) {
			pr("2\n");
			continue;
		}
		//pr("eae\n");
		ll re = 1000001LL;
		ll prx = a, pry = 1;
		ll l = 1, r = 1000000LL;
		ll achou = 0;
		while(l <= r) {
			ll m = (l+r)/2LL;
			ll x = a+m*(a+b);
			ll y = (2LL*m)+1LL;
			if (x == t*y) {
				achou = 1;
				re = y;
				break;
			}
			if (x < t*y) {
				re = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}
		if (achou) {
			pr("%lld\n", re);
		} else {
			ll x = a+re*(a+b);
			ll y = (2LL*re)+1LL;
			re--;
			ll prx = a+re*(a+b);
			ll pry = (2LL*re)+1LL;
			ll mdx = y*prx + x*pry, mdy = y*pry*2LL;
			if (mdx <= t*mdy) {
				pr("%lld\n", pry);
			} else {
				pr("%lld\n", y);
			}
		}
	}
	
 	return 0;
}
