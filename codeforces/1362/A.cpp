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
		sc("%lld %lld", &a, &b);
		if (a == b) {
			pr("0\n");
			continue;
		}
		if (a > b) {
			swap(a, b);
		}
		int qtd = 0;
		while(a < b) {
			if (a*2 == b) {
				a *= 2;
			} else if (a*4 == b) {
				a *= 4;
			} else {
				a *= 8;
			}
			qtd++;
		}
		if (a > b) {
			pr("-1\n");
		} else {
			pr("%d\n", qtd);
		}
	}
 	return 0;
}
