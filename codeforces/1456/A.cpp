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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef EBUG
#include "trace.h"
#else
template<typename... Args>
void trace(Args... args) {}
template<typename... Args>
void recInit(Args... args) {}
template<typename... Args>
void recEnd(Args... args) {}
#endif

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

int li[MAX];
int dp[MAX];

int n, t, a, b, c;
int main(){
	int n, p, k, x, y;
    sc("%d\n", &t);
	while(t--) {
		sc("%d %d %d\n", &n, &p, &k);
		for(int i = 0; i < n; i++) {
			li[i] = getchar() == '1';
		}getchar();
		sc("%d %d\n", &x, &y);
		int resp = 2000000000;
		for(int i = n-1; i >= 0; i--) {
			int tmp = 0;
			if (i+k < n) tmp = dp[i+k];
			if (!li[i]) {
				tmp += x;
			}
			dp[i] = tmp;
			if (i >= p-1) resp = min(resp, (i-(p-1))*y+dp[i]);
			//pr("%d %d %d\n", i, dp[i], resp);
		}
		pr("%d\n", resp);
	}


 	return 0;
}
