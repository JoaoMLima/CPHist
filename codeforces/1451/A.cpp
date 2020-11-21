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

int prop[100000];


int n, t, a, b, c;
int main(){
	vector<int> primes;
	for(int i = 2; i < 100000; i++) {
		if (prop[i] == 0) {
			primes.pb(i);
			for(int j = i+i; j < 100000; j+= i) {
				if (!prop[j]) prop[j] = i;
			}
		}
	}
	sc("%d", &t);
	while(t--){
		sc("%d", &n);
		queue<ii> bfs;
		bfs.push({n, 0});
		while(bfs.front().fi != 1) {
			ii fr = bfs.front();bfs.pop();
			if (fr.fi < 100000) {
				if (prop[fr.fi]) {
					bfs.push({prop[fr.fi], fr.se+1});
				}
				bfs.push({fr.fi-1, fr.se+1});
			} else {
				int mini = -1;
				for(int x : primes) {
					if (fr.fi % x == 0) {
						bfs.push({x, fr.se+1});
						break;
					}
				}
				bfs.push({fr.fi-1, fr.se+1});
			}
		}
		pr("%d\n", bfs.front().se);
		
	}

 	return 0;
}
