#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 300007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}

int li[MAX];

int le[MAX];

int bit2[MAX];

int res[MAX];


ordered_set oset;

void update2(int i, int v) {
	i = MAX-i;
	while(i < MAX) {
		bit2[i] += v;
		i += i&(-i);
	}
}

int query2(int i) {
	i = MAX-i;
	int s = 0;
	while(i) {
		s += bit2[i];
		i -= i&(-i);
	}
	return s;
}
vector<pair<ii, int> > queries;

int main(){
	int t;
	int n, q, a, b;
	sc("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		sc("%d", li+i);
	}

	for(int i = 1; i <= q; i++) {
		sc("%d %d", &a, &b);
		queries.pb({{n-b, a+1}, i});
	}

	sort(queries.begin(), queries.end());

	for(int i = 1; i <= n; i++) {
		if (li[i] == i) {
			le[i] = i;
			oset.insert({le[i], i});
		} else if (li[i] < i && i-li[i] <= sz(oset)) {
			le[i] = oset.find_by_order(sz(oset)-(i-li[i]))->first;
			oset.insert({le[i], i});
		}
	}
	int j = 0;
	for(int i = 1; i <= n; i++) {
		update2(le[i], 1);
		while(j < q && queries[j].fi.fi == i) {
			res[queries[j].se] = query2(queries[j].fi.se);
			j++;
		}
	}

	for(int i = 1; i <= q; i++) {
		pr("%d\n", res[i]);
	}

 	return 0;
}
