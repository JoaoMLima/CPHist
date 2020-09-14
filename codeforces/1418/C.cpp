#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  

#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 300007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update> 

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

int li[2*MAX];
int dpt[2*MAX][2];
int n, t; ll a, b, c;
int dp(int i, int p) {//pos jogador
	if (i >= n) return 0;
	if (dpt[i][p] == -1) {
		if (p == 0) {//amigo
			dpt[i][p] = 2*MAX;
			//tenta 1
			dpt[i][p] = min(dpt[i][p], dp(i+1,!p)+li[i]);
			//tenta 2
			if (i < n-1) {
				dpt[i][p] = min(dpt[i][p], dp(i+2,!p)+li[i]+li[i+1]);
			}
		} else {
			dpt[i][p] = 2*MAX;
			//tenta 1
			dpt[i][p] = min(dpt[i][p], dp(i+1,!p));
			if (i < n-1) {
				dpt[i][p] = min(dpt[i][p], dp(i+2,!p));
			}
		}
	}
	return dpt[i][p];
}

int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
			dpt[i][0] = -1;
			dpt[i][1] = -1;
		}
		pr("%d\n", dp(0, 0));
	}

 	return 0;
}

