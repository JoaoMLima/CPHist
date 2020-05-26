#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010;

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c, m;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &m);
		if (n == 1) {
			pr("%d\n", (m+1)/2);
			continue;
		} else if (m == 1) {
			pr("%d\n", (n+1)/2);
			continue;
		}

		int r =  n*((m+1)/2);
		r = min(r, m*((n+1)/2));
		if (n&1) {
			n --;
			r = min(r, ((m+1)/2) + min(n*((m+1)/2), m*((n+1)/2)));
			n++;
		}
		if (m&1) {
			m--;
			r = min(r, ((n+1)/2) + min(n*((m+1)/2), m*((n+1)/2)));
			m++;
		}
		pr("%d\n", r);

	}
 	return 0;
}
