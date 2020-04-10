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

int n, a, b, c, t;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int pra = 0, prb = 0;
		int ok = 1;
		for(int i = 0; i < n; i++) {
			sc("%d %d", &a, &b);
			if (a < pra || b < prb) ok = 0;
			if (b-prb > a-pra) ok = 0;
			pra = a; prb = b;
		}
		if (ok) pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
