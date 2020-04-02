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

int n, a, b, c, d;
int main(){
	sc("%d %d %d %d", &a, &b, &c, &d);
	int men = max(c, d);
	if (men > 2*c || men > 2*d) {
		pr("-1\n"); return 0;
	}
	int med = max({b, 2*d+1, men+1});
	if (med > 2*b) {
		pr("-1\n"); return 0;
	}
	int gra = max(med+1, a);
	if (gra > 2*a) {
		pr("-1\n"); return 0;
	}
	pr("%d\n%d\n%d\n", gra, med, men);
 	return 0;
}
