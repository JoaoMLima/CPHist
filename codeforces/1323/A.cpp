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

int t, n, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int p = -1;
		int i1 = -1, i2 = -1;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a & 1) {
				if (i1 != -1) i2 = i+1;
				else i1 = i+1;
			} else {
				p = i+1;
			}
		}
		if (p != -1) {
			pr("1\n%d\n", p);
		} else if (i1 != -1 && i2 != -1) {
			pr("2\n%d %d\n", i1, i2);
		} else {
			pr("-1\n");
		}
	}
 	return 0;
}
