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

char s[300010];
int ok[300010];
vector<int> v1;
vector<int> v2;
vector<int> v3;
vector<ii> pts;

int n, t, a, b, c, d;
int main(){
	sc("%d", &n);
	int y = n;
	for(int i = 1; i <= n; i++) {
		sc("%d", &a);
		if (a == 1) v1.pb(i);
		if (a == 2) v2.pb(i); 
		if (a == 3) v3.pb(i);
	}
	sort(v3.begin(), v3.end(), greater<int>());
	set<ii> lib3;
	set<ii> lib2;
	for(int x : v1) {
		lib2.insert({x,y});
		lib3.insert({x,y});
		pts.pb({x, y--});
	}
	/*
	int i = 0, j = 0;
	while(i < sz(v2) && j < sz(v3)) {
		if ()
	}*/
	for(int x : v2) {
		set<ii>::iterator up = lib2.upper_bound({x, 0}); 
		if (up == lib2.end()) {
			pr("-1\n");
			return 0;
		}
		ii x2 = *up;
		pts.pb({x, x2.se});
		lib2.erase(x2);
		lib3.erase(x2);
		lib3.insert({x, x2.se});
	}
	for(int x : v3) {
		set<ii>::iterator up = lib3.upper_bound({x, 0}); 
		if (up == lib3.end()) {
			pr("-1\n");
			return 0;
		}
		ii x2 = *up;
		pts.pb({x2.fi, y});
		lib3.insert({x, y});
		pts.pb({x, y--});
		lib3.erase(x2);
	}

	pr("%d\n", sz(pts));
	for(ii x : pts) {
		pr("%d %d\n", x.se, x.fi);
	}

 	return 0;
}
