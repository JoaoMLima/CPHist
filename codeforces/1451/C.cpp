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

int freq1[105];
int freq2[105];



int t, n, k, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--){
		sc("%d %d\n", &n, &k);
		for(int i = 0; i < 26; i++) {
			freq1[i] = 0;
			freq2[i] = 0;
		}
		for(int i = 0; i < n; i++) {
			freq1[getchar()-'a']++;
		}getchar();
		for(int i = 0; i < n; i++) {
			freq2[getchar()-'a']++;
		}getchar();
		for(int i = 0; i < 26; i++) {
			while (freq1[i] > freq2[i] && freq1[i] >= k) {
				freq1[i] -= k;
				freq1[i+1] += k;
			}
		}
		int ok = 1;
		for(int i = 0; i < 26; i++) {
			if (freq1[i] != freq2[i]) {
				ok = 0;
			}
		}
		pr(ok ? "Yes\n" : "No\n");

	}

 	return 0;
}
