#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, t;
int li[200010];
vector<int> bts[29];
vector<int> resp;
vector<int> final;
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a) {
			for(int j = 29; j >= 0; j--) {
				if (a&(1<<j)) {
					bts[j].pb(a);
					break;
				}
			}
		} else {final.pb(0);}
	}
	for(int j = 29; j >= 0; j--) {
		if ((int)bts[j].size() == 0) {
			continue;
		} else if ((int)bts[j].size() == 1) {
			resp.pb(bts[j][0]);
		} else {
			for (int x : bts[j]) {
				int mandou = 0;
				for(int k = j-1; k >= 0; k--) {
					if (x&(1<<k)) {
						bts[k].pb(x);
						mandou = 1;
						break;
					}
				}
				if (!mandou) {
					final.pb(x);
				}
			}
		}
	}
	for(int x : final) {
		resp.pb(x);
	}
	for(int i = 0; i < (int)resp.size(); i++) {
		if (i) pr(" ");
		pr("%d", resp[i]);
	}pr("\n");
	
 	return 0;
}
