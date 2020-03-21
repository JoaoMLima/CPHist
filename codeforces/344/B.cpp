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
	cin >> a >> b >> c;
	int x = 0, y = 0, z = 0;
	while(a && b || b && c || c && a) {
		if (a >= c && b >= c) {
			a--;b--;x++;
		} else if (b >= a && c >= a) {
			c--;b--;y++;
		} else {
			c--;a--;z++;
		}
	}
	if (a || b || c) {
		pr("Impossible\n");
	} else {
		pr("%d %d %d\n", x, y, z);
	}
 	return 0;
}
