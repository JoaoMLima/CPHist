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

int n, a, b, c, t, m;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &m);
		for(int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == n && j == m) pr("W");
				else pr("B");
			}pr("\n");
		}
	}
 	return 0;
}
