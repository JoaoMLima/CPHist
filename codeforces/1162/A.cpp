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
int n, m, h, a, b, c, l, r;
//vector<int> g[maxn];
char li[50];

int main(){
	sc("%d %d %d\n", &n, &h, &m);
    memset(li, (char)h, sizeof li);
    for(int i = 0 ; i < m; i++) {
        sc("%d %d %d", &a, &b, &c);
        for(char j = (char)a-1; j <= (char)b-1; j++) {
            li[j] = min(li[j], (char)c);
        }
    }
    int res = 0;
    for(int i = 0 ; i < n; i++) {
        res += (int)li[i] * (int)li[i];
    }
    pr("%d\n", res);
 	return 0;
}
