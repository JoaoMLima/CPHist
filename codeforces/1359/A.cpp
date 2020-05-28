#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010;

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d", &a, &b, &c);
		if (b <= a/c) {
			pr("%d\n", b);
		} else {
			int x = b - (a/c);
			int y = (x/(c-1));
			//pr("x %d y %d\n", x, y);
			y += ((x%(c-1)) ? 1 : 0);
			pr("%d\n", (a/c)-y);
		}
	}
	
 	return 0;
}
