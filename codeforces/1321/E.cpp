#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define INF 10000000000000000LL
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

typedef long long ll;
typedef pair<int, int> ii;

ll st[4000010];
ll acum[4000010];

void propagate (int id, int l, int r) {
	if (acum[id]) {
		st[id] += acum[id];
		if (l != r) {
			acum[L(id)] += acum[id];
			acum[R(id)] += acum[id];
		}
		acum[id] = 0LL;
	}
}
void merge (int id, int l, int r) {
	if (l == r)return;
	st[id] = max(st[L(id)]+acum[L(id)], st[R(id)]+acum[R(id)]);
}

void update(int id, int l, int r, int i, int j, ll v) {
	if (r < i || l > j) {
		return;
	}
	if (l >= i && r <= j) {
		acum[id] += v;
		return;
	}
	
	propagate(id, l, r);
	int m = (l+r)>>1;
	update(L(id), l, m, i, j, v);
	update(R(id), m+1, r, i, j, v);
	merge(id, l, r);
}

ll query() {
	return st[0]+acum[0];
}

struct eve {
	ll type, x, y, c;
	bool operator < (eve o) {
		if (x != o.x) return x < o.x;
		if (type != o.type) return type < o.type;
		return false;
	}
};
vector<eve> v;

int main(){
	update(0, 1, 1000000, 1, 1000000, -INF);
	set<int> s;
	
	int n, m, p;ll a, b, cs;
	sc("%d %d %d", &n, &m, &p);
	map<int, ll> ma;
	for(int i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		if (!ma.count(a) || ma[a] > b) ma[a] = b;
	}
	for (pair<int, ll> atk : ma) {
		update(0, 1, 1000000, atk.fi, atk.fi, INF-atk.se);
	}
	for(int i = 0; i < m; i++) {
		sc("%lld %lld", &a, &b);
		v.pb({1, a, 0, b});
	}
	for(int i = 0; i < p; i++) {
		sc("%lld %lld %lld", &a, &b, &cs);
		v.pb({0, b+1, a+1, cs});
	}
	sort(v.begin(), v.end());
	ll maxi = -INF;
	for(eve e : v) {
		if (e.type) {
			maxi = max(maxi, query()-e.c);
		} else {
			update(0, 1, 1000000, e.y, 1000000, e.c);
		}
	}
	
	pr("%lld\n", maxi);
	
 	return 0;
}
