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
int li[110];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		int mini = 110;
		int maxi = -110;
		int sum = 0;
		int qtd0 = 0;
		for(int i = 0; i < n; i++) {
			mini = min(mini, li[i]);
			maxi = max(maxi, li[i]);
			sum += li[i];
			if (li[i] == 0) qtd0++;
		}
		if (sum == 0) {
			if (qtd0) {
				pr("%d\n", qtd0);
			} else {
				pr("1\n");
			}
		} else if (qtd0) {
			int x = qtd0;
			if (sum + qtd0 == 0) x++;
			pr("%d\n", x);
		} else {
			pr("0\n");
		}

	}
 	return 0;
}
