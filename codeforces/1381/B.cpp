#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 4007
#define MOD 1000000007
#define MODL 1000000007LL
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
vector<int> qtds;
int li[MAX];
int dpt[2007];
int n, t;
void build() {
	for(int j = n; j >= 0; j--) {
		dpt[j] = 0;
	}
	dpt[0] = 1;
	for(int i = 0; i < sz(qtds); i++) {
		for(int j = n; j >= qtds[i]; j--) {
			if (dpt[j-qtds[i]]) dpt[j] = 1;
		}
	}
}

int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		qtds.clear();
		for(int i = 1; i <= 2*n; i++) {
			sc("%d", li+i);
		}
		int j = 1;
		for(int i = 2; i <= 2*n; i++) {
			if (li[i] > li[j]) {
				qtds.pb(i-j);
				j = i;
			}
		}
		qtds.pb((2*n)-j+1);
		/*
		for(int qt : qtds) {
			pr("%d ", qt);
		}pr("\n");*/
		build();
		if (dpt[n]) pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
