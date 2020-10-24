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


template <typename T, typename S> 
ostream& operator<<(ostream& os, const pair<T, S>& v) 
{ 
    os << "("; 
    os << v.first << ", " 
       << v.second << ")"; 
    return os; 
} 

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    os << "vector["; 
    for (int i = 0; i < v.size(); ++i) { 
        os << v[i]; 
        if (i != v.size() - 1) 
            os << ", "; 
    } 
    os << "]"; 
    return os; 
}

template <typename T> 
ostream& operator<<(ostream& os, const set<T>& v) 
{ 
    os << "set["; 
    for (auto it : v) { 
        os << it; 
        if (it != *v.rbegin()) 
            os << ", "; 
    } 
    os << "]"; 
    return os; 
}

template <typename T, typename S> 
ostream& operator<<(ostream& os, const map<T, S>& v) 
{ 
    for (auto it : v)  
        os << it.first << " : " 
           << it.second << "\n"; 
      
    return os; 
}


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
struct defNode {
    ll maxi = 0LL, leafs = 0LL, need = 0LL;
    defNode(ll _m, ll _l, ll _n) {
        maxi = _m;leafs = _l; need = _n;
    }
};
ll qtd[2*MAX];
vector<int> g[2*MAX];
defNode dfs(int v) {
    ll maxi = 0;
    ll leafs = 0;
    ll need = 0LL;
    for(int u : g[v]) {
        defNode d = dfs(u);
        if (d.maxi > maxi) {
            need += (d.maxi - maxi)*leafs;
            maxi = d.maxi;
            leafs += d.leafs;
            need += d.need;
        } else if (d.maxi < maxi) {
            d.need += (maxi - d.maxi) * d.leafs;
            leafs += d.leafs;
            need += d.need;
        } else {
            leafs += d.leafs;
            need += d.need;
        }
    }
    if (leafs == 0) {
        //trace(v, "maxi:", qtd[v], "leafs:",  1,"need:", 0);
        return {qtd[v], 1, 0};
    }
    ll x = min(need, qtd[v]);
    need -= x;
    qtd[v] -= x;
    ll q = qtd[v] / leafs;
    ll r = qtd[v] % leafs;
    maxi += q;
    if (r) {maxi++;need += leafs - r;}
    //trace(v, "maxi:", maxi, "leafs:",  leafs,"need:", need);
    return {maxi, leafs, need};
}

int n, t, a, b, c;
int main(){
	sc("%d\n", &n);
    for(int i = 2; i <= n; i++) {
        sc("%d", &a);
        g[a].pb(i);
    }
    for(int i = 1; i <= n; i++) {
        sc("%lld", qtd+i);
    }
    pr("%lld\n", dfs(1).maxi);
 	return 0;
}
