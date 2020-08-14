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



vector<int> lir;
vector<int> lig;
vector<int> lib;
ll dpt[207][207][207];
ll dp(int r, int g, int b) {
    if (r == 0 && g == 0) return 0LL;
    if (r == 0 && b == 0) return 0LL;
    if (g == 0 && b == 0) return 0LL;
    if (dpt[r][g][b] == -1) {
        if (r == 0) dpt[r][g][b] = lig[g-1]*lib[b-1] + dp(r, g-1, b-1);
        else if (g == 0) dpt[r][g][b] = lir[r-1]*lib[b-1] + dp(r-1, g, b-1);
        else if (b == 0) dpt[r][g][b] = lig[g-1]*lir[r-1] + dp(r-1, g-1, b);
        else {
            dpt[r][g][b] = lig[g-1]*lib[b-1] + dp(r, g-1, b-1);
            dpt[r][g][b] = max(dpt[r][g][b], lir[r-1]*lib[b-1] + dp(r-1, g, b-1));
            dpt[r][g][b] = max(dpt[r][g][b], lig[g-1]*lir[r-1] + dp(r-1, g-1, b));
        }
    }
    return dpt[r][g][b];
}
int n, t, r, g, b, a;
int main(){
	sc("%d %d %d\n", &r, &g, &b);
    for(int i = 0; i < r; i++) {
        sc("%d", &a);
        lir.pb(a);
    }
    for(int i = 0; i < g; i++) {
        sc("%d", &a);
        lig.pb(a);
    }
    for(int i = 0; i < b; i++) {
        sc("%d", &a);
        lib.pb(a);
    }
    sort(lir.begin(), lir.end());
    sort(lib.begin(), lib.end());
    sort(lig.begin(), lig.end());
    ll resp = 0;
    memset(dpt, -1, sizeof dpt);
    pr("%lld\n", dp(r, g, b));
 	return 0;
}
