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

char s[105];

int pre[105];
int suf[105];



int t, n, q, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--){
		sc("%d %d\n", &n, &q);
		for(int i = 0; i < n; i++) {
			s[i] = getchar();
		}getchar();
		for(int i = 0; i < q; i++) {
			sc("%d %d\n", &a, &b);
			a--;
			b--;
			int j = 0;
			for(int k = 0; k < n; k++) {
				pre[k] = 0;
				suf[k] = 0;
			}

			for(int k = 0; k < n; k++) {
				if (j < b-a+1) {
					if (s[a+j] == s[k]) {
						j++;
					}
					
				}
				pre[k] = j;
			}
			j = 0;
			for(int k = n-1; k >= 0; k--) {
				if (j < b-a+1) {
					if (s[b-j] == s[k]) {
						j++;
					}
					
				}
				suf[k] = j;
			}
			int res = 0;
			for(int k = 0; k  < n-2; k++) {
				
				if (suf[k+2] >= (b-a+1) -pre[k] && pre[k] && suf[k+2]) {
					res = 1;
				}
			}
			pr(res ? "YES\n" : "NO\n");
		}
	}

 	return 0;
}
