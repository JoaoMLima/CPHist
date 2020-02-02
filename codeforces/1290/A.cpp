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
int li[10000];
int main(){
	int t, m, n, k;
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d", &n, &m, &k);
		k = min(k, m-1);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		int x = 0;
		for(int i = 0; i <= k; i++) {
			//pr("lf: %d rg: %d\n", i, k-i);
			int tmp = 1000000010;
			for(int j = 0; j <= (m-k-1); j++) {
				//pr("qtlf: %d qtrg: %d\n", j, m-k-1-j);
				//pr("tsl: %d tlr: %d\n", li[i+j], li[n-1-(k-i)-(m-k-1-j)]);
				tmp = min(tmp, max(li[i+j], li[n-1-(k-i)-(m-k-1-j)]));
			}
			x = max(x, tmp);
		}
		pr("%d\n", x);
	}
 	return 0;
}
