#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod 1000000009
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define left(x) ((x<<1)+1)
#define right(x) ((x<<1)+2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

void prVector(vi v) {cout << "{";for(int i = 0; i < (int)v.size()-1; i++) {cout << v[i] << ", ";} cout << v[(int)v.size()-1] << "}";}

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
int n, m; 
ld p, q, a, b, c;
struct pt{ld x, y;
    bool operator < (pt o) const { return x*o.y-y*o.x > 0.0;}
    ld operator ^ (pt o) {return x*o.y-y*o.x;}
    pt operator - (pt o) {return {x-o.x, y-o.y};}
    pt operator + (pt o) {return {x+o.x, y+o.y};}
    ld operator ~() {return hypot(x, y);}
    pt operator * (double o) {return {x*o, y*o};}
};
pt linesIntersection(pt a, pt b, pt c, pt d) {
    ld s = (b-a)^(d-c);
    if (fabs(s) < EPS) {//parallel or equal lines
        return pt{1e18, 1e18};
    }
    ld s1 = (c-a)^(d-a);
    return a + ((b-a)*(s1/s));
}

pt li[100010];
vector<pt> hull;


int main(){
    sc("%d %Lf %Lf\n", &n, &p, &q);
    pt dream = {p, q};
    for(int i = 0; i < n; i++) {
        sc("%Lf %Lf\n", &a, &b);
        li[i] = {a, b};
    }
    ld maxx = 0, maxy = 0;
    for(int i = 0; i < n; i++) {
        maxx = max(maxx, li[i].x);
        maxy = max(maxy, li[i].y);
    }
    li[n] = {-1, maxy};
    li[n+1] = {maxx, -1};
    li[n+2] = {0, 0};

    //convex hull
    sort(li, li+n+2);
    hull.pb({0, 0});
    hull.pb(li[0]);
    int sz = 2;
    for(int i = 1; i <= n+2; i++) {
        while(((hull[sz-1]-hull[sz-2])^(li[i]-hull[sz-1])) <= 0) {
            hull.pop_back();sz--;
        }
        hull.pb(li[i]);
        sz++;
    }
    for(int i = 1; i < sz; i++) {
        if ((hull[i-1]^dream) >= -EPS && (hull[i]^dream) <= EPS) {
            pt inter = linesIntersection(hull[i-1], hull[i], {0, 0}, dream);
            //trace(inter.x, inter.y);
            pr("%.12Lf\n", (~dream)/(~inter));return 0;
        }
    }
    //

    return 0;
}