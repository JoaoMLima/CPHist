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
int li[100010];
int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		sort(li, li+n);
		int j = (n-1)/2, k = (n-1)/2;
		pr("%d", li[j]);
		for(int i = 0; i < n-1; i++) {
			if (i % 2 == 0) {
				pr(" %d", li[++k]);
			} else {
				pr(" %d", li[--j]);
			}
		}pr("\n");
	}
 	return 0;
}
