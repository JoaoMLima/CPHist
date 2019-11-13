#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int st[800010];
int li[200010];
int dp[200010];
int accumPower[200010];
void build(int id, int l, int r) {
	if (l == r) {st[id] = li[l];return;}
	int m = (l + r)/2;
	build(L(id), l, m);
	build(R(id), m+1, r);
	st[id] = max(st[L(id)], st[R(id)]);
}

int query(int id, int l, int r, int i, int j) {
	if (l > j || r < i) return 0;
	if(l >= i && r <= j) return st[id];
	int m = (l+r)/2;
	return max(query(L(id), l, m, i, j), query(R(id), m+1, r, i, j));
}

int main(){
    int t, n, x, a, b, y, m;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
		}
		for(int i = 1; i <= n+1; i++) {
			dp[i] = -1;
			accumPower[i] = 0;
		}
		sc("%d", &m);
		for(int i = 1; i <= m; i++) {
			sc("%d %d",&a, &b);
			accumPower[b] = max(accumPower[b], a);
		}
		for(int i = n; i >= 1; i--) {
			accumPower[i] = max(accumPower[i], accumPower[i+1]);
		}
		build(0, 1, n);
		for(int i = 1; i <= n; i++) {
			//pr("i: %d\n", i);
			int l = 1, r = i;
			int resp = -1;
			while(l <= r) {
				int m = (l+r)/2;
				int maxip = query(0, 1, n, i-m+1, i);
				//pr("m: %d maxip: %d i: %d j: %d\n", m, maxip, i-m+1, i);
				if (accumPower[m] >= maxip) {resp = m; l = m+1;}
				else r = m-1;
				//pr("l: %d r: %d\n", l, r);
			}
			//pr("resp: %d\n", resp);
			if (resp == -1 || dp[max(0, i-resp)] == -1) {
				dp[i] = -1;
				//pr("%d ", dp[i]);
			} else {
				dp[i] =  dp[max(0, i-resp)]+1;
				//pr("%d ", dp[i]);
			}
		}//pr("\n");
		pr("%d\n", dp[n]);
	}
 	return 0;
}
