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

int n, t, a, b, c;

int main(){
	sc("%d", &n);
	vector<int> v(20, 0);
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		for(int j = 0; j < 20; j++) {
			if (a&(1<<j)) {
				v[j]++;
			}
		}
	}
	ll s = 0LL;
	while(1) {
		ll x = 0LL;
		for(int j = 0; j < 20; j++) {
			if (v[j]) {
				x += (1<<j);
				v[j]--;
			}
		}
		if (x == 0) break;
		s += x*x;
	}
	pr("%lld\n", s);
	
 	return 0;
}
