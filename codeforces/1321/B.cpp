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

int n, a, b, c;
ll li[200010];
int nxt[200010];
int main(){
	memset(nxt, -1, sizeof nxt);
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", li+i);
	}
	map<ll, int> m;
	for(int i = 0; i < n; i++) {
		if (!m.count(i-li[i])) {
			m[i-li[i]] = i;
		} else {
			nxt[m[i-li[i]]]= i;
			m[i-li[i]] = i;
		}
	}
	ll maxi = 0;
	for(int i = 0; i < n; i++) {
		maxi = max(maxi, li[i]);
		if (nxt[i] != -1) {
			li[nxt[i]] += li[i];
			
		}
	}
	pr("%lld\n", maxi);
 	return 0;
}
