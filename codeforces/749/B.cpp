#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9

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
void prTabs() { range(recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}
bool eq(double a, double b) {return fabs(a - b) < EPS;}
struct pt {double x, y;
    pt(double X = 0.0, double Y = 0.0) { x = X; y = Y;}
};
int n, m;
int a, b, c, x, y, xa, ya, xb, yb, xc, yc;

//vector<int> g[maxn]; 

int main(){
    sc("%d %d", &x, &y);
    sc("%d %d", &xa, &ya);
    sc("%d %d", &xb, &yb);
    int i = 0;
    set<ii> s;
    s.insert({xa + xb - x, ya + yb - y});
    s.insert({xa - (xb - x), ya - (yb - y)});
    s.insert({xa + x - xb, ya + y - yb});
    s.insert({xa -(x - xb), ya - (y - yb)});
    s.insert({x + xb - xa, y + yb - ya});
    s.insert({x - (xb - xa), y - (yb - ya)});
    pr("%d\n", (int) s.size());
    
    for(set<ii>::iterator it = s.begin(); it != s.end(); it++) {
        pr("%d %d\n", (*it).fi, (*it).se);
    }
	
 	return 0;
}
