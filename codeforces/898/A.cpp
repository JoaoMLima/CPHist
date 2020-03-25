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
	if(n%10 >= 5) n += 5;
	n -= (n%10);
	pr("%d\n", n);
 	return 0;
}
