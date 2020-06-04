#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;

int m, n, t, p, a, b, c;

ll modpow(ll a,ll b) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1LL)%MOD;
	ll r = modpow(a, b>>1);
	return r*r%MOD;
}
int li[1025];
int v[1025];
int main(){
	sc("%d", &t);
	
	while(t--) {
		for(int i = 0; i < 1024; i++) {
			li[i] = 0;
		}
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			v[i] = a;
			li[a] = 1;
		}
		int ok = 1;
		for(int i = 1; i < 1024; i++) {
			ok = 1;
			for(int j = 0; j < n; j++) {
				if (li[(v[j]^i)] == 0) {
					ok = 0;
					break;
				}
			}
			if (ok) {
				pr("%d\n", i);
				break;
			}
		}
		if (!ok) {
			pr("-1\n");
		}
	}
 	return 0;
}
