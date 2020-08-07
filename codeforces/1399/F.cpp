#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
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
set<int> seg[6007];
vector<ii> allsegs;
short dpt[6007][6007];
short qtd[6007][6007];
set<int> coords;
int corresp[MAX];


short dp(short l, short r) {
	if (l > r) return 0;
	if (dpt[l][r] == -1) {
		if (l == r) {
			dpt[l][r] = 0;
		} else {
			dpt[l][r] = dp(l+1, r);
			for(int x : seg[l]) {
				if (x < r ) dpt[l][r] = max(dpt[l][r], (short)(dp(l, x) + dp(x+1, r)));
			}
		}
		dpt[l][r] += qtd[l][r];
	}
	return dpt[l][r];
}

int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	memset(dpt, -1, sizeof dpt);
	while(t--) {
		sc("%d\n", &n);
		map<int, int> corresp;
		allsegs.clear();
		coords.clear();
		for(int i = 0; i < n; i++) {
			sc("%d %d", &a, &b);
			coords.insert(a);
			coords.insert(b);
			allsegs.pb({a, b});
		}
		int tmp = 0;
		for(int i : coords) {
			corresp[i] = tmp++;
		}

		for(ii x : allsegs) {
			seg[corresp[x.fi]].insert(corresp[x.se]);
			qtd[corresp[x.fi]][corresp[x.se]]++;
		}
		pr("%d\n", dp(0, tmp));
		
		for(int i = 0; i <= tmp; i++) {
			seg[i].clear();
			for(int j = 0; j <= tmp; j++) {
				dpt[i][j] = -1;
				qtd[i][j] = 0;
			}
		}
		
	}
 	return 0;
}
