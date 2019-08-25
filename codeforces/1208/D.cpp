#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
ll li[200001];
ll bit[200010];
ll query(ll i) {
	i++;
	ll sum = 0;
	while(i) {
		sum += bit[i];
		i -= i&(-i);
	}
	return sum;
}
void update(ll i, ll v) {
	i++;
	while(i < 200010) {
		bit[i] += v;
		i += i&(-i);
	}
}
ll n;
 
int main(){
	sc("%lld", &n);
	set<ll> prox;
	for(ll i = 1; i <= n; i++) {
		prox.insert(i);
		update(i, i);
	}
	for(ll i = 0; i < n; i++) {
		sc("%lld", li+i);
	}
	
	stack<ll> resps;
	for(int i = n-1; i >= 0; i--) {
		set<ll>::iterator it = prox.end();
		ll l = 1, r = *prev(it);
		//pr("%d %d\n", l, r);
		ll f = 1;
		while(l <= r) {
			ll m = (l+r)/2;
			
			ll v = *prox.lower_bound(m);
			ll q = query(v-1);
			//pr("%d %d %d %d\n", m, v, q, li[i]);
			if(q == li[i]) {
				f = v;
				break;
			} else if (q < li[i]){
				l = v+1;
			} else {
				r = m-1;
			}
		}
		prox.erase(f);
		resps.push(f);
		update(f, -f);
	}
	ll p = 0;
	while(!resps.empty()) {
		ll r = resps.top();
		resps.pop();
		if(p) pr(" ");
		pr("%lld", r);
		p = 1;
	}
	pr("\n");
	
	//sc("%d %d", &, &);
	//sc("%d %d %d", &, &, &);
	//sc("%d %d %d %d", &, &, &, &);
	//for (int i = 0; i < ; i++)
 	return 0;
}