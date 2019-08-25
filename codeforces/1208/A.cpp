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
int main(){
	// a - b - a^b - a - b
	sc("%d", &t);
	while(t--) {
	sc("%d %d %d", &a, &b, &n);
	if(n % 3 == 0) pr("%d\n", a);
	if(n % 3 == 1) pr("%d\n", b);
	if(n % 3 == 2) pr("%d\n", a^b);
	}
	//sc("%d %d", &, &);
	//sc("%d %d %d", &, &, &);
	//sc("%d %d %d %d", &, &, &, &);
	//for (int i = 0; i < ; i++)
 	return 0;
}
