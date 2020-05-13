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

int n, k;
int li[100010];
int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &k);
		int resp = 1;
		int temk = 0;
		int segui = 0;
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
			if ((i > 1 && li[i] >= k && li[i-1] >= k) || (i > 2 && li[i] >= k && li[i-2] >= k)) segui = 1;
			if (li[i] == k) temk = 1;
		}
		if (temk && (segui || n == 1)) pr("yes\n");
		else pr("no\n");
	}
 	return 0;
}
