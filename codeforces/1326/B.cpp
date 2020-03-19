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

int n, t, a, b, c;
int main(){
	sc("%d\n", &n);
	int maxi = 0;
	vector<int> ar;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (i) pr(" ");
		pr("%d", a+maxi);
		maxi = max(maxi, a+maxi);
	}pr("\n");
	
 	return 0;
}
