#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
 

 
int n;
ll a, b;
 
int main(){
	int n, m, t;
	vector<ll> res;
	
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", &a);
		res.pb(a);
		
	}
	sort(res.begin(), res.end());
	ll x = 0;
	ll y = 0;
	for(int i = 1; i <= n; i++) {
		if(i+i <= n) {
			x += res[i-1];
		} else {
			y += res[i-1];
		}
	}
	pr("%lld\n", x*x+y*y);
	return 0;
}