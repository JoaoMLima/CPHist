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
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int maxil = -1;
		int minir = 1000000010;
		for(int i = 0; i < n; i++) {
			sc("%d %d", &a, &b);
			maxil = max(maxil, a);
			minir = min(minir, b);
		}
		pr("%d\n", max(0, maxil-minir));
	}
	
	
 	return 0;
}
