#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c;
int main(){
	ll x;
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", &x);
		if (x > 14LL && x % 14LL >= 1LL && x % 14LL <= 6LL) pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
