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
ll li1[40010];
ll li2[40010];
int main(){
	int n, m, a; ll k;
	sc("%d %d %lld", &n, &m, &k);
	int acum = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a) {
			li1[++acum]++;
		} else {
			acum = 0;
		}
	}
	acum = 0;
	for(int i = 0; i < m; i++) {
		sc("%d", &a);
		if (a) {
			li2[++acum]++;
		} else {
			acum = 0;
		}
	}
	for(int i = 40000; i >= 1; i--) {
		li1[i] += li1[i+1];
		li2[i] += li2[i+1];
	}
	//cout << li1[0] << " " << li1[1] << " " << li1[2] << " " << li1[3] << " " << li1[4] << endl;
	//cout << li2[0] << " " << li2[1] << " " << li2[2] << " " << li2[3] << " " << li2[4] << endl;
	ll r = 0LL;
	for(ll i = 1; i*i <= k; i++) {
		if (k % i == 0LL && k/i < 40010) {
			r += li1[i]*li2[k/i];
			if (i*i != k) {
				r += li2[i]*li1[k/i];
			}
		}
	}
	pr("%lld\n", r);
 	return 0;
}
