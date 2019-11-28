#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

struct pt {
	ll x, y;
	bool operator < (pt o) {
		if (x != o.x) return x < o.x;
		return y < o.y;
	}
	pt operator + (pt o) {
		return {x+o.x, y+o.y};
	}
	pt operator - (pt o) {
		return {x-o.x, y-o.y};
	}
	ll operator ~() {
		return x*x+y*y;
	}
	ll operator ^ (pt o) {
		return x*o.y-y*o.x;
	}
	void prt() {
		cout << "{" << x << ", " << y << "}" << endl;
	}
	void prt2() {
		cout << "{" << x/2.0 << ", " << y/2.0 << "}" << endl;
	}
	void prt3() {
		cout << "{" << x/3.0 << ", " << y/3.0 << "}" << endl;
	}
};
vector<pt> poly1;
vector<pt> poly2;
vector<pt> poly3;
vector<pt> poly4;
vector<pt> poly5;

bool intriangle (pt a, pt b, pt c, pt p) {
	return ((b-a)^(p-a)) >= 0LL && ((c-b)^(p-b)) >= 0LL && ((a-c)^(p-c)) >= 0LL;
}

bool insidePoly5(pt p) {
	int l = 1, r = poly5.size()-2;
	while(l < r) {
		int m = (l+r)/2;
		//cout << "l: " << l << endl;
		//cout << "m: " << m << endl;
		//cout << "r: " << r << endl;
		if (((p-poly5[0]) ^ (poly5[m]-poly5[0])) > 0) {
			r = m-1;
		} else if (((p-poly5[0]) ^ (poly5[m]-poly5[0])) < 0) {
			if (intriangle(poly5[0], poly5[m], poly5[m+1], p)) return true;
			l = m+1;
		} else {
			return intriangle(poly5[0], poly5[m], poly5[m+1], p);
		}
	}
	return intriangle(poly5[0], poly5[l], poly5[l+1], p);
}
int main(){
	int n;
	ll a, b;
	sc("%d", &n);
	int inic1 = 0, inic2 = 0, inic3 = 0, inic4 = 0;
	for(int i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		poly1.pb({a, b});
		if (i && (poly1[i] < poly1[inic1])) inic1 = i;
	}
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		poly2.pb({a, b});
		if (i && (poly2[i] < poly2[inic2])) inic2 = i;
	}
	int i = inic1, j = inic2;
	do {
		//cout << "ants:" << endl;
		//poly1[i].prt();
		//poly2[j].prt();

		poly3.pb(poly1[i]+poly2[j]);
		//cout << "adicionado:" << endl;
		//poly3.back().prt2();
		pt p1 = poly1[i]+poly2[(j+1)%poly2.size()];
		pt p2 = poly1[(i+1)%poly1.size()]+poly2[j];
		if (((p1-poly3.back())^(p2-poly3.back())) > 0) {
			j = (j+1)%poly2.size();
		} else if (((p1-poly3.back())^(p2-poly3.back())) < 0) {
			i = (i+1)%poly1.size();
		} else {
			i = (i+1)%poly1.size();
			j = (j+1)%poly2.size();
			/*
			if (~(p1-poly3.back()) > ~(p2-poly3.back())) {
				
			} else {
				
			}*/
		}
	} while(i != inic1 || j != inic2);

	for(i = 0; i < (int)poly3.size(); i++) {
		if (i && (poly3[i] < poly3[inic3])) inic3 = i;
	}

	sc("%d", &n);
	for(i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		poly4.pb({a, b});
		if (i && (poly4[i] < poly4[inic4])) inic4 = i;
	}

	i = inic3, j = inic4;
	//cout << endl << endl;
	
	do {
		//cout << "ants:" << endl;
		//poly3[i].prt();
		//poly4[j].prt();

		poly5.pb(poly3[i]+poly4[j]);
		//cout << "adicionado:" << endl;
		//poly5.back().prt3();
		pt p1 = poly3[i]+poly4[(j+1)%poly4.size()];
		pt p2 = poly3[(i+1)%poly3.size()]+poly4[j];
		if (((p1-poly5.back())^(p2-poly5.back())) > 0) {
			j = (j+1)%poly4.size();
		} else if (((p1-poly5.back())^(p2-poly5.back())) < 0) {
			i = (i+1)%poly3.size();
		} else {
			i = (i+1)%poly3.size();
			j = (j+1)%poly4.size();
			/*
			if (~(p1-poly5.back()) > ~(p2-poly5.back())) {
				
				i = (i+2)%poly3.size();
			} else {
				j = (j+2)%poly4.size();
				
			}*/
		}
	} while(i != inic3 || j != inic4);

	/*
	for(i = 0; i < (int)poly5.size(); i++) {
		pr("%lld %lld\n", poly5[i].x, poly5[i].y);
	}
	*/
	
	sc("%d", &n);
	for(i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		pt p = {3LL*a, 3LL*b};
		pr(insidePoly5(p) ? "YES\n" : "NO\n");
	}

	
 	return 0;
}
