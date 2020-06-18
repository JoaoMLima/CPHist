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

int n, t; ll a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%lld %lld %lld", &a, &b, &c);
		int op = 0;
		if (a < b)swap(a, b);
		while (a <= c) {
			b += a;
			op++;
			swap(a, b);
		}
		pr("%d\n", op);
	}
 	return 0;
}
