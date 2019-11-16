#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, m, a, b, c, t;
ll li[1000100];
ll cla[200010];
int main(){
	sc("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		sc("%lld", li+i);
	}
	sort(li, li+n);
	ll resp = 0LL;
	vector<ll> res;
	int nextcl = 0;
	for(int i = 0; i < n; i++) {
		cla[nextcl] += li[i];
		resp = resp + cla[nextcl];
		nextcl = (nextcl+1)%m;
		res.pb(resp);
	}
	for(int i = 0; i < n; i++) {
		if (i) pr(" ");
		pr("%lld", res[i]);
	}pr("\n");

 	return 0;
}
