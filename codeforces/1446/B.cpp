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

int dp[5007][5007];
vector<char> s;
vector<char> t;
int n, m;

int solve(int i, int j) {
	if (i == n || j == m) {
		return 0;
	}
	if(dp[i][j] == -1) {
		dp[i][j] = 0;
		dp[i][j] = max(dp[i][j], solve(i+1, j)-1);
		dp[i][j] = max(dp[i][j], solve(i, j+1)-1);
		if (s[i] == t[j]) {
			dp[i][j] = max(dp[i][j], solve(i+1, j+1)+2);
		}
	}
	return dp[i][j];
}


int a, b, c;
int main(){
	memset(dp, -1, sizeof dp);
	sc("%d %d\n", &n, &m);
	for(int i = 0; i < n; i++) {
		s.pb(getchar());
	}getchar();
	for(int i = 0; i < m; i++) {
		t.pb(getchar());
	}getchar();
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			maxi = max(maxi, solve(i, j));
		}
	}
	pr("%d\n", maxi);
 	return 0;
}
