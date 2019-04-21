#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) forn(ii, tam) cout << harry[ii] << " \n"[ii == tam -1];
#define forn(i, n) for(int i = 0; i < n; i++)
#define printMatriz(matr, h, w) forn(jj, h) printArr(matr[jj], w);
#define MAXBIT 2000000100LL
#define mod 1234567LL
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e10

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

//Trace dinamico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

//DP debug
int recNum = 0;
void prTabs() { forn(ii,recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

struct pt {ll x, y, id;
	bool operator < (pt o) const {
		if(x != o.x)
			return x < o.x;
		if(y != o.y)
			return y < o.y;
		return id < o.id;
	}
};

bool comp1(pt p, pt q) {
	if(p.x != q.x)
		return p.x < q.x;
	return p.y < q.y; 
}
bool comp2(pt p, pt q) {
	if(p.x != q.x)
		return p.x > q.x;
	return p.y > q.y; 
}
bool comp3(pt p, pt q) {
	if(p.y != q.y)
		return p.y < q.y;
	return p.x < q.x; 
}
bool comp4(pt p, pt q) {
	if(p.y != q.y)
		return p.y > q.y;
	return p.x > q.x; 
}


set<pt> s;
vector<pt> v;
set<pt> Top;
set<pt> Bottom;
set<pt> Left;
set<pt> Right;

int n, m;
ll a, b;
int main(){
	sc("%d %d", &n, &m);
	for(int i = 1 ; i <= n; i++) {
		ll xa, ya, xb, yb;
		sc("%lld %lld %lld %lld", &xa, &ya, &xb, &yb);
		v.pb({xa+xb, ya+yb, i});
	}
	int falta, i, sz = (int)v.size();
	sort(v.begin(), v.end(), comp1);
	falta = m+1;
	i = 0;
	while(i < sz && falta > 0) {
		int x = v[i].x;
		int j = i;
		while(v[j].x == x && j < sz) {
			j++;
		}
		for(int k = i; k < j && k - i+1 <= falta; k++) {
			Left.insert(v[k]); s.insert(v[k]);
		}
		for(int k = j-1; k >= i && j-1-k+1 <= falta; k--) {
			Left.insert(v[k]); s.insert(v[k]);
		}
		falta -= j-i;
		i = j;
	}
	sort(v.begin(), v.end(), comp2);
	falta = m+1;
	i = 0;
	while(i < sz && falta > 0) {
		int x = v[i].x;
		int j = i;
		while(v[j].x == x && j < sz) {
			j++;
		}
		for(int k = i; k < j && k - i+1 <= falta; k++) {
			Right.insert(v[k]); s.insert(v[k]);
		}
		for(int k = j-1; k >= i && j-1-k+1 <= falta; k--) {
			Right.insert(v[k]); s.insert(v[k]);
		}
		falta -= j-i;
		i = j;
	}
	sort(v.begin(), v.end(), comp3);
	falta = m+1;
	i = 0;
	while(i < sz && falta > 0) {
		int y = v[i].y;
		int j = i;
		while(v[j].y == y && j < sz) {
			j++;
		}
		for(int k = i; k < j && k - i+1 <= falta; k++) {
			Bottom.insert(v[k]); s.insert(v[k]);
		}
		for(int k = j-1; k >= i && j-1-k+1 <= falta; k--) {
			Bottom.insert(v[k]); s.insert(v[k]);
		}
		falta -= j-i;
		i = j;
	}
	sort(v.begin(), v.end(), comp4);
	falta = m+1;
	i = 0;
	while(i < sz && falta > 0) {
		int y = v[i].y;
		int j = i;
		while(v[j].y == y && j < sz) {
			j++;
		}
		for(int k = i; k < j && k - i+1 <= falta; k++) {
			Top.insert(v[k]); s.insert(v[k]);
		}
		for(int k = j-1; k >= i && j-1-k+1 <= falta; k--) {
			Top.insert(v[k]); s.insert(v[k]);
		}
		falta -= j-i;
		i = j;
	}
	set<pt>::iterator itLeft, itRight, itBottom, itTop, its;
	ll mini = 2LL*(1e18);
	for(itLeft = Left.begin(); itLeft != Left.end(); itLeft++) {
		for(itRight = Right.begin(); itRight != Right.end(); itRight++) {
			for(itBottom = Bottom.begin(); itBottom != Bottom.end(); itBottom++) {
				for(itTop = Top.begin(); itTop != Top.end(); itTop++) {
					if ((*itRight).x < (*itLeft).x || (*itBottom).x < (*itLeft).x || (*itTop).x < (*itLeft).x) continue;
					if ((*itLeft).x > (*itRight).x || (*itBottom).x > (*itRight).x || (*itTop).x > (*itRight).x) continue;
					if ((*itRight).y < (*itBottom).y || (*itLeft).y < (*itBottom).y || (*itTop).y < (*itBottom).y) continue;
					if ((*itRight).y > (*itTop).y || (*itBottom).y > (*itTop).y || (*itLeft).y > (*itTop).y) continue;
					int out = 0;
					for(its = s.begin(); its != s.end(); its++) {
						if ((*its).x < (*itLeft).x || (*its).x > (*itRight).x || (*its).y < (*itBottom).y || (*its).y > (*itTop).y) out++;
					}
					if (out <= m) {
						int wn = (*itRight).x-(*itLeft).x;
						int w;
						if (wn < 2) w = 1;
						else w = wn / 2 + wn % 2;
						int hn = (*itTop).y-(*itBottom).y;
						int h;
						if (hn < 2) h = 1;
						else h = hn / 2 + hn % 2;
						mini = min(mini, 1LL*w*h);
					}
				}
			}
		}
	}
	pr("%lld\n", mini);
 	return 0;
}
