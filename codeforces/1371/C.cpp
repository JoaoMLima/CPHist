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

int  t;ll n, m,  a, b, c, r;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld %lld %lld", &a, &b, &n, &m);
		if (b > a) swap(a, b);
		if (m > b) {
			pr("No\n");
			continue;
		} else {
			b -= m;
		}
		if (a + b < n) {
			pr("No\n");
		} else {
			pr("Yes\n");
		}
	}
 	return 0;
}
