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

int t, a, b, c;
ll n;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld", &n);
		if (n == 1LL) pr("FastestFinger\n");
		else if (n == 2LL) pr("Ashishgup\n");
		else if (n % 2LL == 1LL) pr("Ashishgup\n");
		else if (__builtin_popcountll(n) == 1) pr("FastestFinger\n");
		else {
		    n /= 2LL;
		    
		    if (n % 2 == 0) pr("Ashishgup\n");
		    else {
		        int prt = 0;
		        for(int i = 2; i*i <= n; i++) {
		            if (n % i == 0) {pr("Ashishgup\n");prt = 1; break;}
		        }
		        if (!prt) pr("FastestFinger\n");
		    }
		}
	}
 	return 0;
}
