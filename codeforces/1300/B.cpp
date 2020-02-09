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
int li[200010];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int maxd = 1000000000;
		for(int i = 0; i < 2*n; i++) {
			sc("%d", li+i);
		}
		sort(li, li+2*n);
		pr("%d\n", abs(li[n-1]-li[n]));

	}
 	return 0;
}
