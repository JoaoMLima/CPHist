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

int n, m, a, b, c;
int main(){
	vector<ii> v;
	sc("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		sc("%d %d", &a, &b);
		v.pb({a, b});
	}
	sort(v.begin(), v.end());
	int x = 0;
	for(int i = 0; i < n; i++) {
		if (v[i].fi <= x) {
			x = max(x, v[i].se);
		}
	}
	if (x >= m) pr("YES\n");
	else pr("NO\n");
 	return 0;
}
