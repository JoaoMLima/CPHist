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
int n, k, a;
int odio[4001][4001];

void populaOdio() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            sc("%d", &a);
            if (i < j) {
                odio[i][j] = a;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            odio[i][j] += odio[i-1][j] + odio[i][j-1] - odio[i-1][j-1];
        }
    }
}
int odioAcumulado(int i, int j) {
    // j maior que i
    return odio[j][j] - odio[j][i-1] - odio[i-1][j] + odio[i-1][i-1];
}
int atual = 0;
int dpt[2][4001];
int ik = 1;
void dp(int l, int r, int OPmin, int OPmax) {
    int m = (l+r)/2;
    if (l > r) return;
    int mini = 1e9;
    int op = m;
    for(int i = max(OPmin, ik-1); i <= min(OPmax, m-1); i++) {
        //trace("i:", i, dpt[!atual][i], odioAcumulado(i+1, m));
        if (dpt[!atual][i] + odioAcumulado(i+1, m) < mini) {
            mini = min(mini, dpt[!atual][i] + odioAcumulado(i+1, m));
            op = i;
        }
    }
    dpt[atual][m] = mini;
    //trace(l, m, r, mini, OPmin, op, OPmax);
    dp(l, m-1, OPmin, op);
    dp(m+1, r, op, OPmax);
}


int main(){
    memset(odio, 0, sizeof odio);
    memset(dpt, -1, sizeof dpt);
	sc("%d %d", &n, &k);
    populaOdio();
    for(int i = 1; i <= n; i++) dpt[!atual][i] = odioAcumulado(1, i);
    //trace(odioAcumulado(1, 3));
    for(int i = 2; i <= k; i++) {
        ik = i;
        dp(1, n, 1, n);
        atual = !atual;
    }
    pr("%d\n", dpt[!atual][n]);
    
 	return 0;
}