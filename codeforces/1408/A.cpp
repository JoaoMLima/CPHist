#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())

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

int a[107];
int b[107];
int c[107];
int r[107];

int n, t, x, y;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", a+i);
		}
		for(int i = 0; i < n; i++) {
			sc("%d", b+i);
		}
		for(int i = 0; i < n; i++) {
			sc("%d", c+i);
		}
		r[0] = a[0];
		for(int i = 1; i < n-1; i++) {
			if (a[i] != r[i-1]) {
				r[i] = a[i];
			} else {
				r[i] = b[i];
			}
		}
		if (a[n-1] != r[n-2] && a[n-1] != r[0]) {
			r[n-1] = a[n-1];
		} else if (b[n-1] != r[n-2] && b[n-1] != r[0]) {
			r[n-1] = b[n-1];
		} else {
			r[n-1] = c[n-1];
		}
		for(int i = 0; i < n; i++) {
			if (i) pr(" ");
			pr("%d", r[i]);
		}pr("\n");
	}
 	return 0;
}
