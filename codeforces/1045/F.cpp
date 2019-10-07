#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
struct pt { ll x, y;
	pt operator - (pt o) {return {x-o.x, y-o.y};}
	ll operator ^ (pt o) {return x*o.y-y*o.x;}
	bool operator == (pt o) {return x == o.x && y == o.y;}
	bool operator != (pt o) {return x != o.x || y != o.y;}
	bool operator < (pt o) const {
		if(x != o.x) return x < o.x;
		return y < o.y;
	}
};
vector<pt> li;
set<pt> p1;
set<pt> p2;
vector<pt> li1;
vector<pt> li2;
vector<pt> hull;
vector<pt> hull1;
vector<pt> hull2;
bool comp(pt p, pt q) {
	if((p^q) == 0) {
		return p.x*p.x+p.y*p.y < q.x*q.x+q.y*q.y;
	}
	return (p^q) > 0;
}
bool comp2(pt p, pt q) {
	return p.x*p.x+p.y*p.y > q.x*q.x+q.y*q.y;
}

int convexHull() {
	sort(li.begin(), li.end());
	if(li[0] != (pt){0,0}) li.pb({0, 0});
	
	sort(li.begin(), li.end());
	
	sort(next(li.begin()), li.end(), comp);
	/*
	for(int i = 0; i < li.size(); i++) {
		pr(" {%lld, %lld}", li[i].x, li[i].y);
	}pr("\n");
	*/
	int i = li.size()-1;
	while(i > 0  && (li[i]^li[li.size()-1]) == 0) i--;
	if (i != 0) sort(next(li.begin(), i+1), li.end(), comp2);
	else return 1;
	li.pb({0, 0});
	/*
	
	for(int i = 0; i < li.size(); i++) {
		pr(" {%lld, %lld}", li[i].x, li[i].y);
	}pr("\n");
	*/
	for(i = 0; i < (int)li.size(); i++) {
		int hs = hull.size();
		while(hull.size() >= 2 && ((hull[hs-1]-hull[hs-2])^(li[i]-hull[hs-1])) < 0) {
			hull.pop_back();
			/*
			pr("%lld\n", ((hull[hs-1]-hull[hs-2])^(li[i]-hull[hs-1])));
			pr("hull:");
			for(int i = 0; i < hull.size(); i++) {
				pr(" {%lld, %lld}", hull[i].x, hull[i].y);
			}pr("\n");
			*/
			hs = hull.size();
		}
		hull.pb(li[i]);
		/*
		pr("hull:");
		for(int i = 0; i < hull.size(); i++) {
			pr(" {%lld, %lld}", hull[i].x, hull[i].y);
		}pr("\n");
		*/
	}
	return 0;
}

int convexHull1() {
	/*
	for(int i = 0; i < li1.size(); i++) {
		pr(" {%lld, %lld}", li1[i].x, li1[i].y);
	}pr("\n");
	*/
	int i = li1.size()-2;
	while(i > 0 && (li1[i]^li1[li1.size()-2]) == 0) i--;
	if (i != 0) sort(next(li1.begin(), i+1), prev(li1.end()), comp2);
	else return 1;
	
	for(i = 0; i < (int)li1.size(); i++) {
		int hs = hull1.size();
		while(hull1.size() >= 2 && ((hull1[hs-1]-hull1[hs-2])^(li1[i]-hull1[hs-1])) <= 0) {
			hull1.pop_back();
			hs = hull1.size();
		}
		hull1.pb(li1[i]);
	}
	return 0;
}

int convexHull2() {

	int i = li2.size()-2;
	while(i > 0 && (li2[i]^li2[li2.size()-2]) == 0) i--;
	if (i != 0) sort(next(li2.begin(), i+1), prev(li2.end()), comp2);
	else return 1;
	for(i = 0; i < (int)li2.size(); i++) {
		int hs = hull2.size();
		while(hull2.size() >= 2 && ((hull2[hs-1]-hull2[hs-2])^(li2[i]-hull2[hs-1])) <= 0) {
			hull2.pop_back();
			hs = hull2.size();
		}
		hull2.pb(li2[i]);
	}
	return 0;
}


int n; ll a, b, c;
int main(){
	sc("%d", &n);
	for (int i = 0; i < n; i++) {
		sc("%lld %lld", &a, &b);
		li.pb({a, b});
	}
	if (convexHull()) {
		int ls = (int)li.size();
		if((li[ls-1].x&1) || (li[ls-1].y&1) || (li[ls-2].x&1) || (li[ls-2].y&1)) {
			pr("Ani\n"); return 0;
		} else {
			pr("Borna\n"); return 0;
		}
	}
	
	
	/*
	for(int i = 0; i < hull.size(); i++) {
		pr(" {%lld, %lld}", hull[i].x, hull[i].y);
	}pr("\n");
	*/
	for(int i = 1; i < hull.size()-1; i++) {
		if(i&1) {
			p1.insert(hull[i]);
		} else {
			p2.insert(hull[i]);
		}
	}

	for(int i = 0; i < li.size(); i++) {
		if(!p1.count(li[i])) {
			li1.pb(li[i]);
		}
		if(!p2.count(li[i])) {
			li2.pb(li[i]);
		}
	}
	
	if (convexHull1()) {
		int ls = (int)li1.size();
		if((li1[ls-1].x&1) || (li1[ls-1].y&1) || (li1[ls-2].x&1) || (li1[ls-2].y&1)) {
			pr("Ani\n"); return 0;
		}
	} else {
		/*
		for(int i = 0; i < hull1.size(); i++) {
		pr(" {%lld, %lld}", hull1[i].x, hull1[i].y);
	}pr("\n");*/
		for(int i = 0; i < hull1.size(); i++) {
			if((hull1[i].x&1) || (hull1[i].y&1)) {
				pr("Ani\n");return 0;
			}
		}
	}

	if (convexHull2()) {
		int ls = (int)li2.size();
		if((li2[ls-1].x&1) || (li2[ls-1].y&1) || (li2[ls-2].x&1) || (li2[ls-2].y&1)) {
			pr("Ani\n"); return 0;
		}
	} else {
		for(int i = 0; i < hull2.size(); i++) {
			if((hull2[i].x&1) || (hull2[i].y&1)) {
				pr("Ani\n");return 0;
			}
		}
	}
/*
	
	for(int i = 0; i < hull1.size(); i++) {
		pr(" {%lld, %lld}", hull1[i].x, hull1[i].y);
	}pr("\n");
	
	
	
	for(int i = 0; i < hull2.size(); i++) {
		pr(" {%lld, %lld}", hull2[i].x, hull2[i].y);
	}pr("\n");
	
*/	
	pr("Borna\n");

	
 	return 0;
}
