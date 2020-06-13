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
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		vector<int> v;
		for(int i = 0; i < n; i++) {
			sc("%d\n", &a);
			if (i <= 1) {
				v.pb(a);
			} else {
				b = v[(int)v.size()-1], c = v[(int)v.size()-2];

				if (abs(c-b) + abs(a-b) <= abs(c-a)) {
					v.pop_back();
				}
				v.pb(a);
			}
		}
		pr("%d\n", (int)v.size());
		for(int i = 0; i < (int)v.size(); i++) {
			if (i) pr(" ");
			pr("%d", v[i]);
		}pr("\n");
	}
 	return 0;
}
