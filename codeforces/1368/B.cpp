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

ll n, t, a, b, c;

int main(){
	sc("%lld", &n);
	vector<ll> v(10, 1LL);
	string s = "codeforces";
	ll qtd = 1LL;
	int i = 0;
	while(qtd < n) {
		qtd = (qtd / v[i])*(v[i]+1);
		v[i]++;
		i = (i+1)%10;
	}
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < v[i]; j++) {
			putchar(s[i]);
		}
	}putchar('\n');
	
 	return 0;
}
