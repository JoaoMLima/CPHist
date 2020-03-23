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
	sc("%d", &n);
	int x1 = 0, x2 = 0;
	while(n--) {
		sc("%d %d", &a, &b);
		if (a > 0) x1++;
		else x2++;
	}
	if (x1 <= 1 || x2 <= 1) pr("Yes\n");
	else pr("No\n");

 	return 0;
}
