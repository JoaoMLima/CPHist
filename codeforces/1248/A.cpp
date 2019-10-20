#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
 

 
int n, a, b;
 
int main(){
	int n, m, t;
	
	sc("%d", &t);
	while(t--) {
		ll np = 0, ni = 0, mp = 0, mi = 0;
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a & 1) ni++;
			else np++;
		}
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a & 1) mi++;
			else mp++;
		}
		pr("%lld\n", np*mp + ni*mi);
	}
	return 0;
}