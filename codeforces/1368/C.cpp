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
	vector<ii> pos;
	pos.pb({0, 1});
	pos.pb({510, 1});
	for(int i = 0; i <= 510; i++) {
		pos.pb({i, 0});
		pos.pb({i, 2});
	}
	int i = 2;
	while(n >= 4) {
		pos.pb({i, -1});
		pos.pb({i, -2});
		pos.pb({i+1, -2});
		pos.pb({i+2, -2});
		pos.pb({i+2, -1});
		pos.pb({i, 1});
		pos.pb({i+2, 1});
		pos.pb({i, 3});
		pos.pb({i, 4});
		pos.pb({i+1, 4});
		pos.pb({i+2, 4});
		pos.pb({i+2, 3});
		i += 4;
		n -= 4;
	}
	if (n) {
		pos.pb({0, -1});
		pos.pb({-1, -1});
		pos.pb({-1, 0});
		n--;
	}
	if (n) {
		pos.pb({0, 3});
		pos.pb({-1, 3});
		pos.pb({-1, 2});
		n--;
	}
	if (n) {
		pos.pb({511, 0});
		pos.pb({511, -1});
		pos.pb({510, -1});
		n--;
	}
	if (n) {
		pos.pb({511, 2});
		pos.pb({511, 3});
		pos.pb({510, 3});
		n--;
	}
	pr("%d\n", (int)pos.size());
	for(int j = 0; j < (int)pos.size(); j++) {
		if (j)pr(" ");
		pr("%d %d\n", pos[j].fi, pos[j].se);
	}
	
 	return 0;
}
