#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 500007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

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

ll maxi[400002];
ll sum[400002];
ll query(int id, int l, int r, int i, int j) {
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return sum[id];
	int m = (l+r)/2;
	return query(L(id), l, m, i, j) + query(R(id), m+1, r, i, j);
}
void update1(int id, int l, int r, int i, int j, ll x) {
	if (l > j || r < i) return;
	if (maxi[id] < x) return;
	if (l == r) {
		sum[id] %= x;
		maxi[id] %= x;
		return;
	}
	int m = (l+r)/2;
	update1(L(id), l, m, i, j, x);
	update1(R(id), m+1, r, i, j, x);
	sum[id] = sum[L(id)]+sum[R(id)];
	maxi[id] = max(maxi[L(id)], maxi[R(id)]);
}

void update2(int id, int l, int r, int i, ll x) {
	if (l > i || r < i) return;
	if (l == r) {
		sum[id] = x;
		maxi[id] = x;
		return;
	}
	int m = (l+r)/2;
	if (i <= m) update2(L(id), l, m, i, x);
	else update2(R(id), m+1, r, i, x);
	sum[id] = sum[L(id)]+sum[R(id)];
	maxi[id] = max(maxi[L(id)], maxi[R(id)]);
}
int n, q, k, a, b, c;
int main(){
	sc("%d %d", &n, &q);
	for(int i = 1; i <= n; i++) {
		sc("%d", &a);
		update2(0, 1, n, i, a);
	}
	for(int i = 1; i <= q; i++) {
		sc("%d", &a);
		if (a == 1) {
			sc("%d %d", &a, &b);
			pr("%lld\n", query(0, 1, n, a, b));
		} else if (a == 2) {
			sc("%d %d %d", &a, &b, &c);
			update1(0, 1, n, a, b, c);
		} else {
			sc("%d %d", &a, &b);
			update2(0, 1, n, a, b);
		}
	}
 	return 0;
}
