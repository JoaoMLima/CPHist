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
int n, m, c, t;
ld p;
//vector<int> g[maxn];

double dpt[2001][2001];
bool solved[2001][2001];

double dp(int a, int b) {

	if(a == 0) return n;
	if(b == 0) return n-a;
	if(!solved[a][b]) {
		dpt[a][b] = p*(dp(a-1, b-1)) + (1-p)*(dp(a, b-1));
		solved[a][b] = true;
	}
	return dpt[a][b];
}

int main(){
	memset(solved, false, sizeof solved);
	sc("%d %Lf %d", &n, &p, &t);
    pr("%lf\n", dp(n, t));
 	return 0;
}