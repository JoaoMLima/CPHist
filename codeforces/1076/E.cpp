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
vi g[300010];
vector<ii> qr[300010];
ll bit[600010];
ll val[300010];
ll query(int i) {
    i++;
    ll s = 0;
    while(i) {
        s += bit[i];
        i -= i&(-i);
    }
    return s;
}
void update(int i, ll v) {
    i++;
    while(i < 600010) {
        //trace("i:", i);
        bit[i] += v;
        i += i&(-i);
    }
}
void dfs(int v, int d, int p) {
    //trace("aqui4");
    for(ii que : qr[v]) {
        update(d, que.se);
        update(d+que.fi+1, -que.se);
    }
    //trace("aqui5");
    val[v] = query(d);
    for(int ch : g[v]) {
        if (ch != p) {
            dfs(ch, d+1, v);
        }
    }
    //trace("aqui6");
    for(ii que : qr[v]) {
        update(d, -que.se);
        update(d+que.fi+1, que.se);
    }
    //trace("aqui7");
}

int main(){
    int n, m, a, b, c;
	sc("%d", &n);
    for(int i = 0; i < n-1; i++) {
        sc("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    //trace("aqui1");
    sc("%d", &m);
    for(int i = 0; i < m; i++) {
        sc("%d %d %d", &a, &b, &c);
        qr[a].pb({min(b, 300000), c});
    }
    //trace("aqui2");
    dfs(1, 0, -1);
    for(int i = 1; i <= n; i++) {
        pr("%lld ", val[i]);
    }
    pr("\n");
    //trace("aqui3");
 	return 0;
}
