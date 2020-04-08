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
ll li[200010];
map<ll, int> m;
int n, a, b, c, t;
int main(){
	sc("%d", &n);
	for(int i = 1; i <= n; i++) {
		sc("%lld", li+i);
		li[i] += li[i-1];
		m[li[i]] = -1;
	}
	m[0] = 0;
	int l = 1;
	ll r = 0LL;
	for(int i = 1; i <= n; i++) {
		l = max(l, m[li[i]]+2);
		//pr("%d\n", x);
		r += max((i-l)+1, 0);
		m[li[i]] = i;
	}
	pr("%lld\n", r);
 	return 0;
}
