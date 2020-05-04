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

int n, a, b, c;
ll li[100010];
int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		int r = 0;
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%lld", li+i);
		}
		for(int i = 1; i < n; i++) {
			if (li[i] < li[i-1]) {
				ll dif =  li[i-1]-li[i];
				ll accum = 0LL;
				int last = 0;
				for(int i = 0; i <= 33; i++) {
					accum += (1LL << i);
				}
				for(int i = 33; i >= 0; i--) {
					if (accum - ((1LL << i)) >= dif) {
						accum -= ((1LL << i));
					} else {
						last = max(last, i);
					}
				}
				r = max(r, last+1);
				li[i] += accum;
			}
		}
		pr("%d\n", r);
	}
 	return 0;
}
