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

int n; ll t, a, b, c;
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		if (b > a) swap(a, b);
		ll dif1 = a-b;
		ll total = 0;
		ll x = min(dif1, b);
		total += x;
		a -= 2*x;
		b -= x;
		x = min(a/3, b/3);
		total += 2*x;
		a -= x*3;
		b -= x*3;
		if (a >= 2 && b >= 1) {
			total++;
			a -= 2; b --;
		}
		pr("%lld\n", total);
	}
 	return 0;
}