#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 2010
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;
int main(){
	int a, b;
	sc("%d %d", &a, &b);
	if(b-a == 1) pr("%d %d\n", a, b);
	else if(a-b==8) pr("9 10\n");
	else if(a == b) pr("%d0 %d1\n", a, a);
	else pr("-1\n");
 	return 0;
}
