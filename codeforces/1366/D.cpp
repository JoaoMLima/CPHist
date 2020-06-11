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

int n, t, a, b, c;
int li[10000007];
ii resp[500007];
int main(){
	sc("%d", &t);
	for(int i = 0; i <= 10000000; i++) {
		li[i] = i;
	}
	for(int i = 2; i*i <= 10000000; i++) {
		if (li[i] == i) {
			for(int j = i*i; j <= 10000000; j += i) {
				if (li[j] == j) {
					li[j] = i;
				}
			}
		}
	}
	for(int i = 0; i < t; i++) {
		sc("%d", &a);
		int x = a;
		int m = li[a];
		while(li[x] == m) {
			x /= m;
		}
		if (x == 1) {
			resp[i] = {-1, -1};
		} else {
			resp[i] = {x, m};
		}
	}
	for(int i = 0; i < t; i++) {
		if (i) pr(" ");
		pr("%d", resp[i].fi);
	}pr("\n");

	for(int i = 0; i < t; i++) {
		if (i) pr(" ");
		pr("%d", resp[i].se);
	}pr("\n");
	
 	return 0;
}
