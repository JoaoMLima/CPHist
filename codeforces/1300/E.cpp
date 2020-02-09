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
ll cross(pt p, pt q) {
	return p.x*q.y-p.y*q.x;
}

vector<pt> resp;
vector<pt> hull;

vector<pt> vt;
int main(){
	sc("%d", &n);
	ll total = 0;
	for(int i = 1; i <= n; i++) {
		sc("%lld\n", &a);
		total += a;
		vt.pb({i, total});
	}
	hull.pb({0, 0});
	for (int i = 0; i < n; i++) {
		while ((int)hull.size() > 1 && cross(hull[(int)hull.size()-1]-hull[(int)hull.size()-2], vt[i]-hull[(int)hull.size()-2]) <= 0) {
			hull.pop_back();
		}
		hull.pb(vt[i]);
	}
	pt ant = {0, 0};
	for(int i = 1; i < (int)hull.size(); i++) {
		ll y = hull[i].y-hull[i-1].y;
		int x = hull[i].x-hull[i-1].x;
		//pr("%lld %lld\n", x, y);
		for(int j = 0; j < x; j++) {
			pr("%.15lf\n", y/(double)x);
		}
	}
	
 	return 0;
}
