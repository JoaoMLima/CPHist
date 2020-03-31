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

int n, a, b, d, x, y, xa, ya, xb, yb,t;
int pri[11] = {2,3,5,7,11,13,17,19,23,29,31};

int c[1007];
int main(){
	sc("%d", &t);
	while(t--) {
		set<int> colors;
		map<int, int> mc;
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			for(int j = 0; j < 11; j++) {
				if (a % pri[j] == 0) {
					colors.insert(j);
					c[i] = j;
					break;
				}
			}
		}
		int k = 1;
		for(int x : colors) {
			mc[x] = k++;
		}
		pr("%d\n", (int)colors.size());
		for(int i = 0; i < n; i++) {
			if (i) pr(" ");
			pr("%d", mc[c[i]]);
		}pr("\n");
	}
 	return 0;
}
