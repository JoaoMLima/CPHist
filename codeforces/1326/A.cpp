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

int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d", &n);
		if (n == 1) {pr("-1\n"); continue;}
		for(int i = 0; i < n; i++) {
			if (i == 0) pr("5");
			else pr("3");
		}pr("\n");
	}
 	return 0;
}
