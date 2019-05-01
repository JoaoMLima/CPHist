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
int l[200];

int main(){
	sc("%d\n", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", l+i);
    }
    int r = 0;
    for(int i = 1; i < n; i++) {
        if (min(l[i], l[i-1]) != 1) {
            pr("Infinite\n"); return 0;
        }
        if (l[i-1] == 1 && l[i] == 2) r += 3;
        if (l[i-1] == 1 && l[i] == 3) r += 4;
        if (l[i] == 1 && l[i-1] == 2) r += 3;
        if (l[i] == 1 && l[i-1] == 3) r += 4;
        if (i >= 2 && l[i] == 2 && l[i-1] == 1 && l[i-2] == 3) r--;
    }
    pr("Finite\n");
    pr("%d\n", r);
 	return 0;
}
