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

int n, t, a, b, c, x, s;
int li[100007];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &x);
		int l = n+1;
		int r = 0;
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
			if (li[i] % x != 0) {
				if (l == n+1) l = i;
				r = i;
			}
		}
		if (l == n+1) {
			pr("-1\n");
			continue;
		}
		if (l == r) {
			pr("%d\n", n);
			continue;
		}
		int s = 0;
		for(int i = l; i <= r; i++) {
			s = (s + li[i]) % x;
		}
		if (s) pr("%d\n", n);
		else pr("%d\n", max(r-1, n-l));
	}
 	return 0;
}
