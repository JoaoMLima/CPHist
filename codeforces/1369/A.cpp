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

int n, t; ll a, b, c;
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", &a);
		if ((270LL*a) % 360LL == 0LL) {
			pr("YES\n");
		} else {
			pr("NO\n");
		}

	}
 	return 0;
}
