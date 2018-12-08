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
int n, m, a, b, c;
ll t;
//vector<int> g[maxn]; 
ll li[200000];
int prox[200000];
int main(){
	sc("%d %lld", &n, &t);
    ll s = 0ll;
    ll r = 0ll;
    for(int i = 0; i < n; i++) {
        sc("%lld", li+i);
        s += li[i];
    }
    for(int i = 0; i < n-1; i++) {
        prox[i] = i+1;
    }prox[n-1] = 0;
    int qnt = (ll)n;
    int ant = n-1;
    int i = 0;
    r = (t / s) * qnt;
    t = t % s;
    while(qnt) {
        //trace(r, qnt, i, li[i], t, prox[i]);
        if (li[i] <= t) {
            r++;
            t -= li[i];
            ant = i;
            i = prox[i];
        } else {
            qnt--;
            prox[ant] = prox[i];
            //trace("a:", prox[ant], "i:", prox[i], qnt);
            s -= li[i];
            if (s) {
                r += (t / s) * qnt;
            t = t % s;
            }
            i = prox[i];
        }
        //trace(r, qnt, i, li[i], t, prox[i]);
    }
    pr("%lld\n", r);
 	return 0;
}