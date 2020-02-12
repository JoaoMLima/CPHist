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

int t, n;
ll a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld %lld", &a, &b, &c);
		ll l = 1, r = 1e18;
		ll resp = r+1;
		while(l <= r) {
			ll m = (l+r)/2;
			ll qtdb = (m / (b+c))*b+((m % (b+c)) ? min(b, m % (b+c)) : 0LL);
			ll qtdc = (m / (b+c))*c+((m % (b+c)) ? max(0LL, (m % (b+c))-b) : 0LL);
			qtdc = min(qtdc, qtdb);
			//pr("%lld: %lld %lld %lld\n", m, qtdb, qtdc, qtdb + qtdc);
			if (qtdb + qtdc >= a) {
				resp = m;
				//pr("%lld\n", resp);
				r = m-1LL;
			} else {
				l = m+1LL;
			}
		}
		pr("%lld\n", resp);
	}
 	return 0;
}
