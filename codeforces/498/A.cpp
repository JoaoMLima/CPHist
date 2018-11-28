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
double a, b, c, x, y, xa, ya, xb, yb;

//vector<int> g[maxn]; 

int main(){
    sc("%lf %lf", &xa, &ya);
    sc("%lf %lf", &xb, &yb);
    sc("%d", &n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        sc("%lf %lf %lf", &a, &b, &c);
        if (eq(a, 0.0)) {
            y = (-c)/b;
            if ((ya > y && yb < y) || (ya < y && yb > y)) {
                s++;
            }
        } else {
            if ((xa - ((-(b*ya) - c)/a) > 0.0 && xb - ((-(b*yb) - c)/a) < 0.0) || (xa - ((-(b*ya) - c)/a) < 0.0 && xb - ((-(b*yb) - c)/a) > 0.0)) {
                s++;
            }
        }
    }
    pr("%d\n", s);
	/*
	//Entrada 1
    while ((ch = getc()) != '\n') {
      s[n++] = ch;
    }
	//Entrada 2
    sc("%d\n", &n);
    for (int i = 0; i < n; i++) {
        sc("%d", li+i);
    }
	//Entrada 3
    sc("%s", &s);
	//Entrada 4
    while(sc("%d\n", &n) != EOF){

    }*/
 	return 0;
}
