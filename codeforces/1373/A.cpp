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

int n, t; ll a, b, c;
int main(){
	sc("%d", &n);
	while(n--) {
		sc("%lld %lld %lld", &a, &b, &c);
		if (a < c) pr("1");
		else pr("-1");
pr(" ");
		if (c < b*a) pr("%lld", b);
		else pr("-1");
pr("\n");
	}
 	return 0;
}
