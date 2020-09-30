#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}


bool eq(ld d1, ld d2) { return fabs(d1 - d2) < EPS;}
bool dif(ld d1, ld d2) { return !eq(d1, d2);}
bool men(ld d1, ld d2) { return d1 + EPS < d2;}
bool mai(ld d1, ld d2) { return d1 > d2 + EPS;}

ld li[MAX];

int n, t, k, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d", &n, &k);
		for(int i = 0; i < n; i++) {
			sc("%Lf", li+i);
		}
		ld x = 0, y = k;
		ld vx = 1, vy = 1;
		ld s = 0;
		int i = 0, j = n-1;
		while(j >= i) {
			ld d1 = (y-x)/(vx+vy);
			ld d2 = (li[i]-x)/vx;
			ld d3 = (y-li[j])/vy;
			if (!mai(d1, d2) && !mai(d1, d3)) {
				x += d1*vx;
				y -= d1*vy;
				i++;
				j--;
				s += d1;
			} else if (eq(d2, d3)) {
				vx++;vy++;
				x = li[i];
				y = li[j];
				i++;j--;
				s += d2;
			} else if (men(d2, d3)) {
				vx++;
				x = li[i];
				i++;
				s += d2;
				y -= d2*vy;
			} else {
				vy++;
				y = li[j];
				j--;
				s += d3;
				x += d3*vx;
			}
		}
		pr("%.12Lf\n", s + fabs(y-x)/(vx+vy));
	}
 	return 0;
}
