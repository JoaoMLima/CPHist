#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;

int n, m;
int seq[2][100010];

int  maxi[100010];
int    dp[100010];
int accum[100010];

int main(){
	cin >> n;
	string s;
	cin >> s;
	s = "x"+s;
	for(int i = 1; i <= n; i++) {
		int ant = seq[0][i-1];
		if (s[i] == 'a' || s[i] == '?') seq[1][i] = ant+1;
		else seq[1][i] = 0;
		ant = seq[1][i-1];
		if (s[i] == 'b' || s[i] == '?') seq[0][i] = ant+1;
		else seq[0][i] = 0;
	}

	for(int i = 1; i <= n; i++) {
		accum[i] = accum[i-1];
		if (s[i] == '?') accum[i]++;
	}

	cin >> m;
	
	for(int i = 1; i <= n; i++) {
		maxi[i] = maxi[i-1];
		if (seq[m%2][i] >= m) {
			maxi[i] = maxi[i-m]+1;
		}
	}

	for(int i = 1; i <= n; i++) {
		dp[i] = dp[i-1];
		if (maxi[i] > maxi[i-1]) dp[i] = dp[i-m]+accum[i]-accum[i-m];
		else if (seq[m%2][i] >= m) {
			dp[i] = min(dp[i], dp[i-m]+accum[i]-accum[i-m]);
		}
	}
	
	pr("%d\n", dp[n]);
 	return 0;
}
