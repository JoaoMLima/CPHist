#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, t;
int li[1000100];
int lp[1000100];
int main(){
	vector<int> parts;
	int ab = 0;
	int ok = 1;
	int prt = 1;
	int lastpr = -1;
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a > 0) {
			if (li[a]) {ok = 0; break;}
			else {
				if (lp[a] == prt) {
					ok = 0; break;
				}
				lp[a] = prt;
				ab++;li[a] = 1;
			}
		} else {
			if (li[-a]) {ab--;li[-a] = 0;}
			else {ok = 0; break;}
		}
		if (ok && !ab) {prt++;parts.pb(i-lastpr); lastpr = i;}
	}
	if (!ok || lastpr != n-1) {pr("-1\n"); return 0;}
	pr("%d\n", (int)parts.size());
	int pt = 0;
	for(int p : parts) {
		if (pt) pr(" ");
		pt = 1;
		pr("%d", p);
	}pr("\n");

 	return 0;
}
