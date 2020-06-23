#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;

int n, t, k; ll a, b, c;
int dp[2000007];
int rt[2000007];
int main(){
	sc("%d", &t);
	for(int i = 3; i < 2000007; i++) {
		dp[i] = ((dp[i-1]+dp[i-2])%MOD+dp[i-2])%MOD;
		if (!rt[i-1] && !rt[i-2]) {
			rt[i] = 1;
			dp[i] = (dp[i]+4)%MOD;
		}
	}
	while(t--) {
		sc("%d", &n);
		pr("%d\n", dp[n]);
	}
 	return 0;
}
