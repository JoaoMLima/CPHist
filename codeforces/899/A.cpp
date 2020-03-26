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
	int q1 = 0, q2 = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a == 1) q1++;
		else q2++;
	}
	pr("%d\n", min(q1, q2) + (q1-min(q1, q2))/3);
 	return 0;
}
