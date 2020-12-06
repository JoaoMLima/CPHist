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
int inversions = 0;


char grid[307][307];

//tipo1 = XOA
//tipo2 = OXA

int pos(int i, int j) {
	return (((j-i)%3)+3)%3;
}
vector<ii> v;

int n, t, a, b, c;
int main(){
    sc("%d\n", &t);
	while(t--) {
		v.clear();
		v.pb({0, 0});
		v.pb({0, 1});
		v.pb({0, 2});
		int qt1 = 0, qt2 = 0;
		inversions = 0;
		sc("%d\n", &n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				grid[i][j] = getchar();
				if (grid[i][j] != '.') {
					v[pos(i, j)].fi++;
				}
			}getchar();
		}
		sort(v.begin(), v.end());
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (grid[i][j] != '.') {
					if (pos(i, j) == v[0].se) {
						if (grid[i][j] == 'X') {
							qt2++;
						} else {
							qt1++;
						}
					} else if (pos(i, j) == v[1].se) {
						if (grid[i][j] == 'O') {
							qt2++;
						} else {
							qt1++;
						}
					}
				}
			}
		}
		if (qt1 <= qt2) {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if (grid[i][j] != '.') {
						if (pos(i, j) == v[0].se) {
							grid[i][j] = 'X';
						} else if (pos(i, j) == v[1].se) {
							grid[i][j] = 'O';
						}
					}
				}
			}
		} else {
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					if (grid[i][j] != '.') {
						if (pos(i, j) == v[0].se) {
							grid[i][j] = 'O';
						} else if (pos(i, j) == v[1].se) {
							grid[i][j] = 'X';
						}
					}
				}
			}
		}

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				putchar(grid[i][j]);
			}putchar('\n');
		}
		//pr("%d %d\n", qt1, qt2);
	}

 	return 0;
}
