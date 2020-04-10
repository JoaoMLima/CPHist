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
ll li[100000];

int n, a, b, c, t;
int main(){
	sc("%d", &t);
	while(t--) {
		ll x;
		sc("%d %lld", &n, &x);
		for(int i = 0; i < n; i++) {
			sc("%lld", li+i);
		}
		sort(li, li+n);
		ll s = 0;
		int r = 0;
		for(int i = n-1; i >= 0; i--) {
			s += li[i];
			if (s/(n-i) >= x) r = n-i;
		}
		pr("%d\n", r);
	}
 	return 0;
}
