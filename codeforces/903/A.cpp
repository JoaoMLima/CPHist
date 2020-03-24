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
int main(){
	int t;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int ok = 0;
		for(int i = 0; i <= n/7; i++) {
			if ((n-(7*i))%3 == 0) {
				pr("YES\n");
				ok = 1;break;
			}
		}
		if (!ok) pr("NO\n");
	}
 	return 0;
}
