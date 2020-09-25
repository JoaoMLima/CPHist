#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define MAX 100007

typedef long long ll;

int li[3*MAX];
int pi[3*MAX];
int va[3*MAX];
ll resp = 0LL;
int n, t, q, a, b, c;

void clear(int i) {
	if (i < 0 || i > n-1) return;
	if (pi[i]) {
		resp -= li[i];
		pi[i] = 0;
	} else if (va[i]){
		resp += li[i];
		va[i] = 0;
	}
}
void calc(int i) {
	if (i < 0 || i > n-1 || pi[i] || va[i]) return;
	if ((i == 0 || li[i] > li[i-1]) && (i == n-1 || li[i] > li[i+1])) {
		pi[i] = 1;
		resp += li[i];
	} else if (i > 0 && i < n-1 && li[i] < li[i-1] && li[i] < li[i+1]) {
		va[i] = 1;
		resp -= li[i];
	}
}


int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d", &n, &q);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
			pi[i] = 0;
			va[i] = 0;
		}
		resp = 0LL;
		
		for(int i = 0; i < n; i++) calc(i);

		pr("%lld\n", resp);
		while(q--) {
			sc("%d %d", &a, &b);
			a--;b--;
			for(int i = a-1; i <= a+1; i++) clear(i);
			for(int i = b-1; i <= b+1; i++) clear(i);

			swap(li[a], li[b]);

			for(int i = a-1; i <= a+1; i++) calc(i);
			for(int i = b-1; i <= b+1; i++) calc(i);

			pr("%lld\n", resp);
		}
	}
 	return 0;
}