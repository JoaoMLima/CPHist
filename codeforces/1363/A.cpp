#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010;

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c, x;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &x);
		int qtdi = 0;
		int qtdp = 0;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a&1) qtdi++;
			else qtdp++;
		}
		int tot = 0;
		if (!qtdi){
			pr("No\n");
			continue;
		}
		qtdi--;
		tot++;
		int mini = min(x-tot, qtdi);
		if (mini&1) mini--;
		tot += mini;
		mini = min(x-tot, qtdp);
		tot += mini;
		if (x==tot) pr("Yes\n");
		else pr("No\n");
	}
 	return 0;
}
