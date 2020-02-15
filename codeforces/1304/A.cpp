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
	int t, d, x, y;
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d %d", &x, &y, &a, &b);
		if ((y-x)%(a+b) == 0) {
			pr("%d\n", ((y-x)/(a+b)));
		} else {
			pr("-1\n");
		}

	}
 	return 0;
}
