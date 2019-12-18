#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
map<vector<ii>, int> mp;
int n, k, a;
int li[100010];
vector<ii> fp[100010];
int main(){
	sc("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	for(int i = 0; i < n; i++) {
		int x = li[i];
		int j = 2;
		while(j*j <= x) {
			while(x%j == 0) {
				if(!fp[i].empty() && fp[i][(int)fp[i].size()-1].first == j) {
					fp[i][(int)fp[i].size()-1].second++;
				} else {
					fp[i].pb({j, 1});
				}
				x/= j;
			}
			j++;
		}
		if(x != 1) {
			fp[i].pb({x, 1});
		}
		/*
		pr("%d:", li[i]);
		for(ii x : fp[i]) {
			pr("{%d, %d} ", x.first, x.second);
		}pr("\n");*/
	}//pr("\n");
	ll r = 0LL;
	for(int i = 0; i < n; i++) {
		vector<ii> ori;
		vector<ii> inv;
		
		for(int j = 0; j < fp[i].size(); j++) {
			fp[i][j].second %= k;
			if(fp[i][j].second) {
				ori.pb(fp[i][j]);
				fp[i][j].second = k - fp[i][j].second;
				inv.pb(fp[i][j]);
			}
		}
		/*
		pr("%d:", li[i]);
		for(ii x : ori) {
			pr("{%d, %d} ", x.first, x.second);
		}pr("\n");
		
		for(ii x : inv) {
			pr("{%d, %d} ", x.first, x.second);
		}pr("\n");*/
		
		if(mp.count(inv)) {
			r += (ll)mp[inv];
		}
		if(mp.count(ori)) {
			mp[ori]++;
		} else {
			mp[ori] = 1;
		}
	}
	pr("%lld\n", r);
 	return 0;
}
