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
int li[100010];
int n, a, b, c, t, m;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		int sobe = 0;
		int desce = 0;
		int ok = 1;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a > li[i] && !sobe) ok = 0;
			if (a < li[i] && !desce) ok = 0;
			if (li[i] == -1) desce = 1;
			if (li[i] == 1) sobe = 1;
		}
		if (ok)pr("YES\n");
		else pr("NO\n");
	}
 	return 0;
}
