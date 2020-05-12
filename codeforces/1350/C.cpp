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

int n, a, b, c;
int cri[200010];
int mini[200010];
int mini2[200010];
int chances[200010];
int li[200010];
int main(){
	set<int> primes;
	for(int i = 1; i <= 200000; i++) {
		mini[i] = 1000000;
		mini2[i] = 1000000;
		cri[i] = i;
	}
	for(int i = 2; i <= 200000; i++) {
		if (cri[i] == i) {
			primes.insert(i);
			chances[i] = 2;
			if (i < 1000) {
				for(int j = i*i; j <= 200000; j+= i) {
					if (cri[j] == j) {
						cri[j] = i;
					}
				}
			}
		}
	}
	sc("%d", &n);
	ll resp = 1LL;
	for(int i = 1; i <= n; i++) {
		sc("%d", li+i);
	}
	for(int i = 1; i <= n; i++) {
		int x = li[i];
		vector<int> toErase;
		for(int p : primes) {
			int qtd = 0;
			while(x % p == 0) {
				x /= p;
				qtd++;
			}
			
			if (qtd < mini[p]) {
				mini2[p] = mini[p];
				mini[p] = qtd;
			} else if (qtd < mini2[p]) {
				mini2[p] = qtd;
			}
			if (qtd == 0) {
				chances[p]--;
				if (!chances[p]) toErase.pb(p);
			}
			//pr("p: %d -> %d ", p, qtd);
		}//pr("\n");
		for(int p : toErase) {
			primes.erase(p);
		}
	}
	for(int p : primes) {
		int ant = -1;
		int r = mini2[p];
		//pr("p: %d -> %d\n", p, r);
		for(int i = 0; i < r; i++) {
			resp *= p;
		}
	}
	pr("%lld\n", resp);
 	return 0;
}
