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

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

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
ll bit[MAX];

ll query(int i) {
    i = 200003-i;
    ll s = 0;
    while(i) {
        s += bit[i];
        i -= i&(-i);
    }
    return s;
}

void update(int i, ll v) {
    i = 200003-i;
    while (i < MAX) {
        bit[i] += v;
        i += i&(-i);
    }
}
ordered_set tudo;
ordered_set luz;
ordered_set fogo;

int n, t, r, g, b, a, c;
map<int, int> corresp;
set<int> entr;


vector<ii> entrada;
int main(){
	sc("%d\n", &n);
    for(int i = 0; i < n; i++) {
        sc("%d %d", &a, &b);
        entrada.pb({a, b});
        entr.insert(abs(b));
    }
    int y = 1;
    for(int x : entr) {
        corresp[x] = y++;
    }
    for(int i = 0; i < n; i++) {
        a = entrada[i].fi, b = entrada[i].se, c = corresp[abs(entrada[i].se)];
        if (b < 0) {
            tudo.erase(c);
            if (!a) fogo.erase(c);
            else luz.erase(c);
            update(c, b);
        } else {
            tudo.insert(c);
            if (!a) fogo.insert(c);
            else luz.insert(c);
            update(c, b);
        }
        if (!sz(tudo)) {
            pr("0\n");
        } else if (!sz(fogo)) {
            pr("%lld\n", query(1) + query((*tudo.find_by_order(sz(tudo)-sz(luz)))+1));
        } else if (!sz(luz)) {
            pr("%lld\n", query(1));
        } else if ((*fogo.find_by_order(sz(fogo)-1)) >= (*tudo.find_by_order(sz(tudo)-sz(luz)))) {
            pr("%lld\n", query(1) + query(*tudo.find_by_order(sz(tudo)-sz(luz))));
        } else {
            pr("%lld\n", query(1) + query((*fogo.find_by_order(sz(fogo)-1))) - query((*fogo.find_by_order(sz(fogo)-1)+1)) + query((*tudo.find_by_order(sz(tudo)-sz(luz)))+1));
        }
    }
    
 	return 0;
}
