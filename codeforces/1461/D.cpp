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
set<ll> resps;

void getResps(vector<int> &v) {
	ll sum = 0LL;
	for(int i = 0; i < sz(v); i++) {
		sum += v[i];
	}
	resps.insert(sum);
	if (v[0] == v[sz(v)-1]) return;

	int m = (v[0] + v[sz(v)-1])/2;
	vector<int> v2;
	int qtdtira = 0;
	for(int i = 0; i < sz(v); i++) {
		if (v[i] > m) {v2.pb(v[i]);qtdtira++;}
	}
	for(int i = 0; i < qtdtira; i++) {
		v.pop_back();
	}
	getResps(v);
	getResps(v2);
}

int n, t, q, a, b, c;
int main(){
    sc("%d", &t);
	while(t--) {
		resps.clear();
		sc("%d %d", &n, &q);
		vector<int> v1;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			v1.pb(a);
		}
		sort(v1.begin(), v1.end());
		getResps(v1);
		for(int i = 0; i < q; i++) {
			sc("%d", &a);
			if (resps.count(a)) pr("Yes\n");
			else pr("No\n");
		}
	}

 	return 0;
}
