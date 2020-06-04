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

int t; ll n, a, b, c;
int main(){
	sc("%d", &t);
	ll qtd[61];
	qtd[0] = 1LL;
	qtd[1] = 3LL;
	qtd[2] = 7LL;
	for(int i = 3; i < 61; i++) {
		qtd[i] = qtd[i-1] + (qtd[i-1]-i) + (i+1LL);
	}
	/*
	for(int i = 0; i < 4; i++) {
		pr("%lld\n", qtd[i]);
	}pr("\n");*/
	while(t--) {
		sc("%lld", &n);
		ll r = 0LL;
		for(int i = 60; i >= 0; i--) {
			if (n >= (1LL<<i)) {
				n -= (1LL<<i);
				r += qtd[i];
			}
		}
		pr("%lld\n", r);
	}
 	return 0;
}
