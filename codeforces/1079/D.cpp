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
ld a, b, c, xa, ya, xb, yb;
//vector<int> g[maxn]; 
bool eq(ld d1, ld d2) { return fabs(d1 - d2) < EPS;}
struct pt {ld x, y, z;
    pt(ld X = 0.0L, ld Y = 0.0L, ld Z = 0.0L) { x = X; y = Y; z = Z;}
    pt operator - (pt o) { //Point diference
        return pt(x - o.x, y - o.y, z - o.z);
    }
    ld operator ^ (pt o) { //Distance point to point
        return hypot(x - o.x, y - o.y);
    }
};
char ch;
int main(){
    sc("%Lf %Lf %Lf\n", &a, &b, &c);
    sc("%Lf %Lf %Lf %Lf\n", &xa, &ya, &xb, &yb);
    pt A = pt(xa, ya);
    pt B = pt(xb, yb);
    pt A1 = pt(xa, ya);
    pt A2 = pt(xa, ya);
    pt B1 = pt(xb, yb);
    pt B2 = pt(xb, yb);
    if(!eq(b, 0.0L)) {
        A1.y = (-c -(a*A.x))/b;
        B1.y = (-c -(a*B.x))/b;
    } else {
        A1.y = 1e21;
        B1.y = 1e21;
    }
    if(!eq(a, 0.0L)) {
        A2.x = (-c -(b*A.y))/a;
        B2.x = (-c -(b*B.y))/a;
    } else {
        A2.x = 1e21;
        B2.x = 1e21;
    }
    ld r = fabs(A.x - B.x) + fabs(A.y - B.y);
    r = min(r, (A ^ A1) + (A1 ^ B1) + (B1 ^ B));
    r = min(r, (A ^ A1) + (A1 ^ B2) + (B2 ^ B));
    r = min(r, (A ^ A2) + (A2 ^ B1) + (B1 ^ B));
    r = min(r, (A ^ A2) + (A2 ^ B2) + (B2 ^ B));
    pr("%.15Lf\n", r);
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
