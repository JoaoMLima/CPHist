#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int n, t; ll a, b, c;
ll li[200007];
ll dpi[200007];
ll dpv[200007];
int main(){
	sc("%d\n", &t);

	while(t--) {
		sc("%d", &n);
		ll total = 0LL;
		for(int i = 1; i <= n; i++) {
			sc("%lld", li+i);
			if (i % 2 == 1) total += li[i];
			if (i%2 == 1) li[i] = -li[i];
		}
		ll resp = total;
		for(int i = 0; i <= n+1; i++) {
			dpi[i] = 0;
			dpv[i] = 0;
		}
		for(int i = 1; i <= n; i++) {
			dpi[i] = max(li[i], dpi[i-1]+li[i]);
		}
		for(int i = n; i >= 1; i--) {
			dpv[i] = max(li[i], dpv[i+1]+li[i]);
		}
		/*
		for(int i = 1; i <= n; i++) {
			pr("%lld ", dpi[i]);
		}pr("\n");
		for(int i = 1; i <= n; i++) {
			pr("%lld ", dpv[i]);
		}pr("\n");
		*/
		for(int i = 1; i <= n; i++) {
			if (i % 2 == 1) {
				resp = max(resp, total + li[i] + max(dpi[i-1], dpv[i+1]));
			}
		}
		pr("%lld\n", resp);


	}
 	return 0;
}
