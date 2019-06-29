#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define pb push_back
#define EPS 1e-8

int n, m;
double a, b;
struct pt {double x, y;
	double r(double xa) { return ((xa-x)*(xa-x)+y*y)/(2*y); }
};
vector<pt> v;

double calculaRaio(double x) {
	double maxi = 0.0;
	for(pt p: v) maxi = max(maxi, p.r(x));
	return maxi;
}

double ternary(double l, double r) {
	double x1, x2;
	while(r-l > EPS) {
		x1 = 2*l/3+r/3, x2 = l/3+2*r/3;
		a = calculaRaio(x1);
		b = calculaRaio(x2);
		if (a > b) l = x1;
		else r = x2;
	}
	return a;
}


int main(){
	sc("%d\n", &n);
	int neg = 0;
	int pos = 0;
	for(int i = 0; i < n; i++) {
		sc("%lf %lf", &a, &b);
		if (b > 0) pos++;
		else neg++;
		v.pb({a, fabs(b)});
	}
	if (neg && pos) {
		pr("-1\n"); return 0;
	}
	pr("%.10lf\n", ternary(-1e7, 1e7));
 	return 0;
}
