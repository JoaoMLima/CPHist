#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
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
int n, m, a, b, c, k;

namespace std {
template <> struct hash<std::pair<int, int>> {
    inline size_t operator()(const std::pair<int, int> &v) const {
        std::hash<int> int_hasher;
        return int_hasher(v.first) ^ int_hasher(v.second);
    }
};
}
//vector<int> g[maxn];
int li[200000];
unordered_map<ii, int> ma;
unordered_map<ii, int> ma2;
int ndigits(int nu) {
    int di = 10;
    for(int i = 1000000000; i >= 10; i/=10) {
        if(!(nu/i)) {di--;}
        else {return di;}
    }
    return 1;
}
void insere(int i, int nd) {
    ii p = mp(i, nd);
    if(ma.count(p)) {
        ma[p]++;
    } else {
        ma[p] = 1;
    }
}
int find(int i, int nd) {
    int mo = i % k;
    int r = 0;
    if(mo == 0) {
        r += ma[mp(0, nd)];
    } else {
        r += ma[mp(k - mo, nd)];
    }
    return r;
}
void insere2(int i, int nd) {
    ii p = mp(i, nd);
    if(ma2.count(p)) {
        ma2[p]++;
    } else {
        ma2[p] = 1;
    }
}
int find2(int i, int nd) {
    int mo = i % k;
    int r = 0;
    if(mo == 0) {
        r += ma2[mp(0, nd)];
    } else {
        r += ma2[mp(k - mo, nd)];
    }
    return r;
}

int main(){
    sc("%d %d", &n, &k);
    ll r = 0;
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        li[n-1-i] = a;
        ll al = a+0ll;
        int nd = ndigits(a);
        r += find(a, nd) + 0ll;
        for(int j = 1; j <= 10; j++) {
            al = (al * 10ll) % (k+0ll);
            insere((int)al, j);
        }
    }
    for(int i = 0; i < n; i++) {
        ll al = li[i]+0ll;
        int nd = ndigits(li[i]);
        r += find2(li[i], nd) + 0ll;
        for(int j = 1; j <= 10; j++) {
            al = (al * 10ll) % (k+0ll);
            insere2((int)al, j);
        }
    }
    pr("%lld\n", r);
 	return 0;
}