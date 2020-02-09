#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n;
ll a, b, c, t;
struct pt {
	ll x, y;
	pt operator - (pt o) {
		return {x-o.x, y-o.y};
	}
	bool opo(pt o) { return (-o.x == x) && (-o.y == y);}
};
vector<pt> li;
vector<pt> vt;
int main(){
	sc("%d", &n);
	if (n &1) {
		pr("NO\n");
	} else {
		for(int i = 0; i < n; i++) {
			sc("%lld %lld", &a, &b);
			li.pb({a, b});
			if (i) {
				pt q = li[i]-li[i-1];
				ll g = __gcd(abs(q.x), abs(q.y));
				//q.x /= g;
				//q.y /= g;
				vt.pb(q);
				//pr("{%lld %lld}\n", vt[(int)vt.size()-1].x, vt[(int)vt.size()-1].y);
			}
		}
		vt.pb(li[0]-li[n-1]);
		//pr("{%lld %lld}\n", vt[(int)vt.size()-1].x, vt[(int)vt.size()-1].y);
		int ok = 1;
		for(int i = 0; i < n; i++) {
			if (!vt[i].opo(vt[(i+(n/2))%n])) ok = 0;
		}
		if (ok) pr("YES\n");
		else pr("NO\n");
	}
	
	
 	return 0;
}
