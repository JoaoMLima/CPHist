#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, t;
int li[100010];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int maxi = INT_MIN;
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			li[i] = a-li[i];
			maxi = max(maxi, li[i]);
		}
		int ok = 1;
		if (maxi < 0) {
			ok = 0;
		}

		for(int i = 0; i < n; i++) {
			if (li[i] != 0 && li[i] != maxi) {
				ok = 0;
				break;
			}
		}
		int lastmaxi = -1;
		for(int i = 0; i < n; i++) {
			if (lastmaxi != -1 && li[i] == maxi && lastmaxi != i-1) {
				ok = 0;
				break;
			}
			if (li[i] == maxi) {
				lastmaxi = i;
			}
		}

		if (ok) pr("YES\n");
		else pr("NO\n");

	}
 	return 0;
}
