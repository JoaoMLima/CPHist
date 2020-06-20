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

int n, t, a, b, c;
int li[2007];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		vector<int> imp;
		vector<int> par;
		for(int i = 1; i <= 2*n; i++) {
			sc("%d", &a);
			if (a&1)imp.pb(i);
			else par.pb(i);
		}
		if (((int)imp.size())&1) {
			imp.pop_back();
			par.pop_back();
		} else {
			if (((int)imp.size()) >= 2) {
				imp.pop_back();
				imp.pop_back();
			} else {
				par.pop_back();
				par.pop_back();
			}
		}
		for(int i = 0; i < ((int)imp.size()); i += 2) {
			pr("%d %d\n", imp[i], imp[i+1]);
		}
		for(int i = 0; i < ((int)par.size()); i += 2) {
			pr("%d %d\n", par[i], par[i+1]);
			
		}
	}
 	return 0;
}
