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

int n, a, b, c;
int main(){
	sc("%d", &n);
	sc("%d", &a);
	sc("%d", &b);
	for(int i = 0; i <= n; i+= a) {
		if ((n-i)%b == 0) {
			pr("YES\n");
			pr("%d %d\n", i/a, (n-i)/b);
			return 0;
		}
	}
	pr("NO\n");
 	return 0;
}
