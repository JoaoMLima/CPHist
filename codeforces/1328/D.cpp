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

int n, a, b, t;
int li[200010];
int c[200010];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		int tudoigual = 1;
		int seguidosiguais = 0;
		for(int i = 0; i < n; i++) {
			if (li[i] != li[(i+1)%n]) tudoigual = 0;
			if (li[i] == li[(i+1)%n]) seguidosiguais = 1;
		}
		if (tudoigual) {
			pr("1\n");
			for(int i = 0; i < n; i++) {
				if (i) pr(" ");
				pr("1");
			}pr("\n");
		} else if (n % 2 == 0) {
			pr("2\n");
			for(int i = 0; i < n; i++) {
				if (i) pr(" ");
				pr(i % 2 ? "1" : "2");
			}pr("\n");
		} else if (n % 2 == 1 && !seguidosiguais) {
			pr("3\n");
			for(int i = 0; i < n; i++) {
				if (i) pr(" ");
				pr(i == n-1 ? "3" : (i % 2 ? "1" : "2"));
			}pr("\n");
		} else {
			pr("2\n");
			int trocado = 0;
			c[0] = 1;
			pr("1");
			for(int i = 1; i < n; i++) {
				if (li[i] == li[i-1] && !trocado) {
					c[i] = c[i-1];
					trocado = 1;
				} else if (li[i] == li[(i-1+n)%n]) {
					c[i] = (c[i-1] == 1 ? 2 : 1);
				} else {
					c[i] = (c[i] = c[i-1] == 1 ? 2 : 1);
				}
				pr(" %d", c[i]);
			}pr("\n");
		}

	}
 	return 0;
}
