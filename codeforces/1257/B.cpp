#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    int t, n, x, a, b, y;
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &x, &y);
		if (x == 1) {
			if (y == 1) pr("YES\n");
			else pr ("NO\n");
		} else if (x == 2 || x == 3) {
			if (y == 1 || y == 2 || y == 3) pr("YES\n");
			else pr ("NO\n");
		} else {
			pr("YES\n");
		}
	}
 	return 0;
}
