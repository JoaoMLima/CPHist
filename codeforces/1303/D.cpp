#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

ll n, m, a, b, c;
ll qt[60];
ll obj[60];
ll pot[60];
map<ll, int> ma;
int main(){
	int t;
	
	sc("%d", &t);
	ll x = 1;
	for(int i = 0; i < 60; i++) {
		ma[x] = i;
		pot[i] = x;
		x *= 2LL;
	}
	while(t--) {
		memset(qt, 0, sizeof qt);
		memset(obj, 0, sizeof obj);
		sc("%lld %lld", &n, &m);
		for(int i = 59; i >= 0; i--) {
			if (n >= pot[i]) {
				obj[i]++;
				n-= pot[i];
			}
		}
		for(int i = 0; i < m; i++) {
			sc("%lld", &a);
			qt[ma[a]]++;
		}
		int ok = 1;
		ll div = 0;
		for(int i = 0; i < 60; i++) {
			//pr("%lld %lld\n", obj[i], qt[i]);
			if (obj[i] <= qt[i]) {
				qt[i] -= obj[i];
				if (i < 59) {
					qt[i+1] += qt[i]/2LL;
				}
			} else {
				for(int j = i+1; j < 60; j++) {
					if (qt[j]) {
						qt[j]--;
						for(int k = j-1; k >= i; k--) {
							div++;
							qt[k]++;
						}
						qt[i]--;
						break;
					} else if (j == 59){
						ok = 0;
					}
				}
				if (ok == 0) break;
			}
		}
		if (ok == 0) {
			pr("-1\n");
		} else {
			pr("%lld\n", div);
		}
	}
 	return 0;
}
