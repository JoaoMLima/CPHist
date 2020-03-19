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

int n, k, a, b, c;
int main(){
	sc("%d %d\n", &n, &k);
	int last = -1;
	ll possi = 1LL;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (last != -1 && a > n-k) {
			possi = possi*(i-last)%998244353LL;
		}
		if (a > n-k) last = i;
	}
	pr("%lld %lld\n", (n-k+1LL+n)*k/2LL, possi);
	
 	return 0;
}
