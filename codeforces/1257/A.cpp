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
    int t, n, x, a, b;
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d %d", &n, &x, &a, &b);
		if (a > b) swap(a, b);
		int dis = b-a;
		int maxi = n-1;
		pr("%d\n", min(dis+x, maxi));
	}
 	return 0;
}
