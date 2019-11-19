#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int medi(int l, int r) {
	return (r+l)/2;
}

int main(){
	int n, a;
	sc("%d\n", &n);
	vector<int> ps;
	vector<int> divi;
	
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a) ps.pb(i);
	}
	
	if (ps.size() <= 1) {
		pr("-1\n");
		return 0;
	}
	for(int i = 2; i <= (int)ps.size(); i++) {
		if((int)ps.size() % i == 0) {
			divi.pb(i);
		} 
	}
	ll best = 100000000000LL;
	for(int i = 0; i < (int)divi.size(); i++) {
		int d = divi[i];
		ll sm = 0LL;
		for(int j = 0; j < (int)ps.size(); j +=d) {
			int l = j, r = j+d-1;
			int m = medi(l, r);
			for(int k = l; k <= r; k++) {
				sm += abs(ps[k]-ps[m]);
			}
		}
		//pr("%lld\n", sm);
		best = min(best, sm);
	}
	pr("%lld\n", best);
	

	
 	return 0;
}
