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
int op[300010];
vi g[300010];
ii dfs(int v) {
	if ((int)g[v].size() == 0) {
		return {1,1};
	} else {
		ii res;
		if (op[v]) {
			res = {300010, 0};
		} else {
			res = {0, 0};
		}
		for(int child: g[v]) {
			ii df = dfs(child);
			res.se += df.se;
			if (op[v]) {
				res.fi = min(df.fi, res.fi);
			} else {
				res.fi += df.fi;
			}
		}
		return res;
	}
}

int main(){
	sc("%d\n", &n);
	for(int i = 1; i <= n; i++) {
		sc("%d", op+i);
	}
	for(int i = 2; i <= n; i++) {
		sc("%d", &a);
		g[a].pb(i);
	}
	ii res = dfs(1);
	pr("%d\n", res.se-res.fi+1);
 	return 0;
}
