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


int t, n, k, a;
int used[100010];
int matched[100010];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 1; i <= n; i++) {
			used[i] = 0;
			matched[i] = 0;
		}
		for(int i = 1; i <= n; i++) {
			sc("%d", &k);
			for(int j = 1; j <= k; j++) {
				sc("%d", &a);
				if (!used[a] && !matched[i]) {matched[i] = 1; used[a] = 1;}
			}
		}
		int pri = 0, kng = 0;
		for(int i = 1; i <= n; i++) {
			if (!used[i] && !kng) kng = i;
			if (!matched[i] && !pri) pri = i;
		}
		if (!pri) pr("OPTIMAL\n");
		else pr("IMPROVE\n%d %d\n", pri, kng);
	}

 	return 0;
}
