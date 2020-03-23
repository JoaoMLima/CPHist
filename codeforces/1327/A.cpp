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


int t; ll n, k, a;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld", &n, &k);
		n -= (1LL+((k-1LL)*2LL+1LL))*k/2;
		//pr("%lld\n", n);
		if (n >= 0 && n % 2 == 0) pr("YES\n");
		else pr("NO\n");
	}

 	return 0;
}
