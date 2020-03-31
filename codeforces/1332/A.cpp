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

int n, a, b, c, d, x, y, xa, ya, xb, yb,t;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d %d", &a, &b, &c, &d);
		sc("%d %d %d %d %d %d", &x, &y, &xa, &ya, &xb, &yb);
		if ((a > 0 || b > 0) && xa == xb) {
			pr("No\n");continue;
		}
		if ((c > 0 || d > 0) && ya == yb) {
			pr("No\n");continue;
		}
		
		
		int tmp = max(a-b, 0);
		b = max(b-a, 0);
		a = tmp;
		tmp = max(c-d, 0);
		d = max(d-c, 0);
		c = tmp;



		if (abs(x-xa) < a) {
			pr("No\n"); continue;
		}
		if (abs(x-xb) < b) {
			pr("No\n"); continue;
		}

		if (abs(y-ya) < c) {
			pr("No\n"); continue;
		}

		if (abs(y-yb) < d) {
			pr("No\n"); continue;
		}
		pr("Yes\n");

		
	}
 	return 0;
}
