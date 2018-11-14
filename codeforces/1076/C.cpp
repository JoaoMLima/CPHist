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
#define EPS 1e-9L
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
int n, m;
ld a, b, c, d;
//vector<int> g[maxn]; 

int main(){
    sc("%d\n", &n);
    for(int i = 0; i < n; i++) {
        sc("%Lf\n", &d);
        ld de = d*d - 4.0L*d;
        if (de < 0.0L) {
            pr("N\n"); continue;
        }
        ld b1 = (-d + sqrt(de))/(-2.0L), b2 = (-d - sqrt(de))/(-2.0L);
        pr("Y %.15Lf %.15Lf\n", b1, b2);
        /*
        double ini = 0.0, fim = d;
        b = (ini + fim)/2.0;
        while (fabs(b/(b-1) - d + b) > EPS) {
            //cin >> c;
            //trace(b, b/(b-1), d, b/(b-1) - d + b, fabs(fabs(b/(b-1) - d + b)));
            if (b/(b-1) - d + b > EPS) {
                //trace("-a");
                fim = b;
            } else {
                //trace("-b");
                ini = b;
            }
            //trace(ini, fim);
            b = (ini + fim)/2.0;
        }
        pr("Y %.15lf %.15lf\n", d - b, b);*/
    }
 	return 0;
}