#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, m, b, c;
int main(){
	sc("%d %d", &n, &m);
	if(n == 1 && m == 1) {
		pr("0\n");
		return 0;
	}
	vector<int> r;
	vector<int> c;
	if(n < m) {
		for(int i = 1; i <= n; i++) {
			r.pb(i);
		}
		for(int i = n+1; i <= n+m; i++) {
			c.pb(i);
		}
	} else {
		for(int i = 1; i <= m; i++) {
			c.pb(i);
		}
		for(int i = m+1; i <= n+m; i++) {
			r.pb(i);
		}
	}
	for(int x : r) {
		int p = 0;
		for(int y : c) {
			if(p)pr(" ");
			p = 1;
			pr("%d", x*y);
		}
		pr("\n");
	}

 	return 0;
}
