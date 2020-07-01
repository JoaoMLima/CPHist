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

int p, n, a;
int li[100007];
int main(){
	sc("%d %d", &n, &p);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	sort(li, li+n);
	int l = 1, r = 1000000000;
	int lb = 1000000000, ub = 1000000001;
	while(l <= r) {
		int m = (l+r)/2;
		int x = m;
		int ok = 1;
		for(int i = 0; i < n; i++) {
			if (x < li[i]) {ok = 0; break;}
			x++;
		}
		if (ok) {
			lb = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	//pr("%d %d\n", lb, ub);
	l = lb, r = 1000000000;
	while(l <= r) {
		int m = (l+r)/2;
		
		int x = m;
		int ok = 0;
		for(int i = 0; i < n; i++) {
			int l2 = i, r2 = n-1;
			int maxi = l2;
			while(l2 <= r2) {
				int m2 = (l2+r2)/2;
				if (li[m2] <= x) {
					maxi = m2;
					l2 = m2+1;
				} else {
					r2 = m2-1;
				}
			}
			//pr("i: %d maxi: %d p: %d\n", i, maxi, p);
			if (maxi-i+1 >= p) {
				ok = 1;
				break;
			}
			x++;
		}
		//pr("m: %d ok: %d\n", m, ok);
		if (ok) {
			ub = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	//pr("%d %d\n", lb, ub);
	pr("%d\n", ub-lb);
	int prt = 0;
	for(int i = lb; i < ub; i++) {
		if (prt) pr(" ");
		prt = 1;
		pr("%d", i);
	}pr("\n");
 	return 0;
}
