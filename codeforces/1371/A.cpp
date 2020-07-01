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
	sc("%d", &n);
	while(n--) {
		sc("%d", &a);
		pr("%d\n", a/2+a%2);
	}
 	return 0;
}
