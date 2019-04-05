#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define modL 1000000007LL
#define mdL(x) ((((x) % modL) + modL) % modL)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

//Trace dinamico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

//DP debug
int recNum = 0;
void prTabs() { range(recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}
int n, m, a, b, c, h, w;
vector<ii> pts;
ll fact[200000];
ll invFact[200000];

ll comb[2002][2002];

ll dpt[2002][2002];

ll modPow(ll a, ll b) {
    if (b == 0) return 1LL;
    if (b & 1LL) return a * modPow(a, b-1LL) % modL;
    ll r = modPow(a, b>>1);
    return r * r % modL;
}
ll dp(int i, int j) {
    if (dpt[i][j] == -1LL) {
        dpt[i][j] = comb[i][j];
        for(int k = i+1; k < j; k++) {
            dpt[i][j] -= dp(i, k) * comb[k][j] % modL;
            if (dpt[i][j] < 0) dpt[i][j] += modL;
        }
    }
    return dpt[i][j];
}


int main(){
    memset(dpt, -1, sizeof dpt);
    fact[0] = 1LL;
    for(int i = 1; i < 200000; i++) {
        fact[i] = fact[i-1]*i%modL;
    }
    for(int i = 0; i < 200000; i++) {
        invFact[i] = modPow(fact[i], modL-2LL);
    }
    sc("%d %d %d\n", &h, &w, &n);
    if(h == 1 && w == 1) {pr("1\n");return 0;}
    pts.pb({1, 1});
    pts.pb({h, w});
    for(int i = 0; i < n; i++) {
        sc("%d %d", &a, &b);
        pts.pb({a, b});
    }
    sort(pts.begin(), pts.end());
    for(int i = 0; i < (int)pts.size(); i++){
        for(int j = i+1; j < (int)pts.size(); j++){
            if (pts[j].se < pts[i].se) comb[i][j] = 0LL;
            else {
                ll difr = pts[j].fi - pts[i].fi;
                ll difc = pts[j].se - pts[i].se;
                comb[i][j] = fact[difr + difc] * invFact[difr] % modL * invFact[difc] % modL;
            }
        }
    }
    

    pr("%lld\n", dp(0, (int)pts.size()-1));
 	return 0;
}
