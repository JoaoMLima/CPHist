#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9

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
ll a, b, c;
int main(){
    vector<double> roots;
    sc("%lld %lld %lld", &a, &b, &c);
    if (a == 0) {
        if (b == 0) {
            if (c == 0) {
                pr("-1\n");return 0;
            }
        } else {
            roots.pb(-1.0*c/b);
        }
    } else {
        ll delta = b*b-4*a*c;
        if (delta > 0) {
            roots.pb((-b+sqrt(delta))/(2*a));
            roots.pb((-b-sqrt(delta))/(2*a));
        } else if (delta == 0) {
            roots.pb((-b+sqrt(delta))/(2*a));
        }
    }
    pr("%d\n", (int)roots.size());
    sort(roots.begin(), roots.end());
    for(double root : roots) {
        pr("%.10lf\n", root);
    }
    return 0;
}