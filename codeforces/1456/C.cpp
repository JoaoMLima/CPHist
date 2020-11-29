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

ll li[5*MAX];
vector<ll> part[5*MAX];

int t, a, b, c;
int main(){
	int n, p, k, x, y;
    sc("%d %d\n", &n, &k);
	for(int i = 0; i < n; i++) {
		sc("%lld", li+i);
	}
	k++;
	sort(li, li+n, greater<ll>());
	vector<ll> neg;
	ll tmp = 0;
	int i = 0;
	ll resp = 0;
	for(; i < n; i++) {
		resp += tmp;
		if (tmp + li[i] < 0) {
			neg.pb(tmp+li[i]);
			//trace(tmp+li[i]);
			i++;
			break;
		}
		tmp += li[i];
	}
	for(; i < n; i++) {
		neg.pb(li[i]);
		//trace(li[i]);
	}

	sort(neg.begin(), neg.end(),  greater<ll>());
	for (i = 0; i < sz(neg); i++) {
		part[i%k].pb(neg[i]);
	}
	for(i = 0; i < k; i++) {
		tmp = 0;
		//trace("grp", i);
		for(int j = 0; j < sz(part[i]); j++) {
			resp += tmp;
			//trace(tmp, part[i][j]);
			tmp += part[i][j];
		}
	}

	pr("%lld\n", resp);

 	return 0;
}
