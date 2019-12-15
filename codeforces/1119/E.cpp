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


ll li[300010];
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", li+i);
	}
	ll r = 0;
	ll extras = 0;
	for(int i = 0; i < n; i++) {
		ll tmp = min(li[i]/2, extras);
		r += tmp;
		extras -= tmp;
		li[i] -= tmp*2;
		r += li[i]/3;
		extras += li[i]%3;
	}

	pr("%lld\n", r);

 	return 0;
}