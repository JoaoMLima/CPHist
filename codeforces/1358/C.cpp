#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200010

typedef long long ll;
typedef pair<int, int> ii;

int n, t; ll a, b, c, d;
int li[MAX];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld %lld %lld", &a, &b, &c, &d);
		ll dd = c-a;
		ll dr = d-b;
		ll t = dd+dr;
		ll r = t*(1+t)/2LL;
		t -= dd;
		r -= t*(1+t)/2LL;
		t = dd;
		r -= t*(1+t)/2LL;
		pr("%lld\n", r+1);

	}
 	return 0;
}
