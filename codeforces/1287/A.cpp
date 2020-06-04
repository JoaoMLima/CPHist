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
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		int r = 0;
		int s = INT_MIN;
		for(int i = 0; i < n; i++) {
			if (getchar() == 'A') {
				s = 0;
			} else {
				s++;
				r = max(r, s);
			}
		}getchar();
		pr("%d\n", r);
	}
 	return 0;
}
