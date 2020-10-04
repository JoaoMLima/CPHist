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


vector<int> d[100][100];
int n, t, a, b, c, m;
int main(){
	sc("%d\n", &t);

	while(t--) {
		sc("%d %d", &n, &m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				sc("%d", &a);
				d[min(i, n-1-i)][min(j, m-1-j)].pb(a);
			}
		}
		ll r = 0;
		for(int i = 0; i < 100; i++) {
			for(int j = 0; j < 100; j++) {
				if (!sz(d[i][j]))continue;
				sort(d[i][j].begin(), d[i][j].end());
				ll obj = d[i][j][(sz(d[i][j])-1)/2];
				for (int x : d[i][j]) {
					r += abs(x-obj);
				}
				d[i][j].clear();
			}
		}
		pr("%lld\n", r);
	}
 	return 0;
}
