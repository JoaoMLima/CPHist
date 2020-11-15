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

vector<int> li;

int solve(int bit, vector<int> v) {
	if (sz(v) == 1) return 0;
	int resp = sz(v)-1;
	vector<int> v1;
	vector<int> v2;
	for(int x : v) {
		if (x & (1<<bit)) v2.pb(x);
		else v1.pb(x);
	}
	if (!sz(v1)) resp = min(resp, solve(bit-1, v2));
	else if (!sz(v2)) resp = min(resp, solve(bit-1, v1));
	else {
		resp = min(resp, sz(v1)-1 + solve(bit-1, v2));
		resp = min(resp, sz(v2)-1 + solve(bit-1, v1));
	}
	return resp;
}

int n, t, a, b, c;
int main(){
    sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		li.pb(a);
	}
	pr("%d\n", solve(29, li));
 	return 0;
}
