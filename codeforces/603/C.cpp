#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-6
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
int n, k, a;
int main(){
    scanf("%d %d", &n, &k);
    ll resp = 0;
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        if (k & 1) {
            if (a == 1) resp ^= 1;
            else if (a == 2) resp ^= 0;
            else if (a == 3) resp ^= 1;
            else if (a != 0 && !(a & 1)) {
                int xo = 2;
                while(!(a&1)) {
                    xo = -xo + 3;
                    a >>= 1;
                }
                if (a == 3) xo = -xo + 3;
                //trace(xo);
                resp ^= xo;
            }
        } else {
            if (a == 1) resp ^= 1;
            if (a == 2) resp ^= 2;
            else if (a != 0 && !(a & 1)) resp ^= 1;
        }
    }
    if (resp) pr("Kevin\n");
    else pr("Nicky\n");
 	return 0;
}