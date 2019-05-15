#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-6
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
int n, b, c, k, x;
ll a;
ll li[5001];
ll dp[4*5001];
int ind[4*5001];
ll diminui[5001];
int lx[5001];
ll l, r, m;

int zeraDp() {memset(lx, -1, sizeof lx);
    for(int i = 0; i < 4*5001; i++){
        dp[i] = LLONG_MIN;
        ind[i] = INT_MIN;
    }}
pair<ll, int> query(int id, int l, int r, int i, int j){
    //trace(id, l, r, i, j);
    if (l > r || l > j || r < i) return {LLONG_MIN, -1};
    if (l >= i && r <= j) return {dp[id], ind[id]};
    int m = (l+r)/2;
    pair<ll, int> q1 = query(id*2+1, l, m, i, j), q2 = query(id*2+2, m+1, r, i, j);
    //trace(q1.fi, q2.fi, l, r, i, j);
    if (q1.fi > q2.fi) return q1;
    else return q2;
}
void update(int id, int l, int r, int i, pair<ll, int> v){
    if (l == r) {
        //trace("l = r = ", l);
        dp[id] = v.fi;
        ind[id] = v.se;
        return;
    }
    int m = (l+r)/2;
    if (i <= m) update(id*2+1, l, m, i, v);
    else update(id*2+2, m+1, r, i, v);

    dp[id] = dp[2*id+1]; ind[id] = ind[2*id+1];
    if (dp[2*id+2] > dp[id]) {
        dp[id] = dp[2*id+2]; ind[id] = ind[2*id+2];
    }
}
pair<ll, int> getMaxDp(int i) {
    return query(0, 0, 5000, max(0, i-k), i-1);
}
void updMaxDp(ll newVal, int newIndex, int i) {
    update(0, 0, 5000, i, {newVal, newIndex});
}
void populaDp() {
    zeraDp();
    for(int i = 0; i < n; i++) {
        //trace("i:", i);
        ll cost = li[i]+m;
        // /trace("cost[", i, "]:", cost);
        ll maxi = LLONG_MIN;
        int maxiX = 1;
        diminui[i] = 0;
        if (i < k) {
            maxi = max(maxi, cost);
            diminui[i] = m+i;
        }
        if (i > 0) {
            pair<ll, int> pa = getMaxDp(i);
            //trace("que",0, 0, 5000, max(0, i-k), i-1);
            //trace(pa.fi, pa.se);
            

            if (pa.fi+cost > maxi){
                maxi = pa.fi+cost;
                maxiX = lx[pa.se]+1;
                diminui[i] = diminui[pa.se]+m+i;
            }
        }
        
        //trace("lx[", i, "]:", maxiX);
        //trace("dp[", i, "]:", maxi);
        //trace("upd",0, 0, 5000, i, maxi, i);
        updMaxDp(maxi, i, i);
        lx[i] = maxiX;
    }
}

int main(){
    sc("%d %d %d", &n, &k, &x);
    ll maxi = 0;
    
    for(int i = 0; i < n; i++){
        sc("%lld", &a);
        li[i] = a*10000+i;
        //trace(li[i]);
        maxi = max(maxi, li[i]);
    }
    
    int mini = ((n-k+1)/k)+(((n-k+1)%k) ? 1 : 0);
    if (x < mini) {
        pr("-1\n");return 0;
    }
    
    li[n] = n;diminui[n] = n;
    n++;
    
    
    
    //trace(maxi);
    l = -5000*maxi-1; r = 0;
    while (1) {
        m = (l+r)/2;
        //trace("l, m, r:", l, m, r);
        cin >> a;
        populaDp();
        //trace("lx:",lx[n-1]-1, "query:", query(0, 0, 5000, n-1, n-1).fi);
        if (lx[n-1]-1 == x) {
            break;
        } else if (lx[n-1]-1 < x){
            l = m+1;
        } else {
            r = m-1;
        }
    }
    pr("%lld\n", (query(0, 0, 5000, n-1, n-1).fi-diminui[n-1])/10000);
 	return 0;
}