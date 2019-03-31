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
int direcao[200001]; //1 sai do vertice - 0 entra no vertice
vi g[200001];
vi edge;

int dfs(int i) {
	for(int j = 0; j < (int)g[i].size(); j++) {
		if (direcao[g[i][j]] != -1) {
			//trace(direcao[g[i][j]], direcao[i]);
			if (direcao[g[i][j]] != !(direcao[i])) {
				return 0;
			}
		} else {
			direcao[g[i][j]] = !(direcao[i]);
			if (!dfs(g[i][j])) return 0;
		}
	}
	return 1;
}

int main(){
	memset(direcao, -1, sizeof direcao);
	sc("%d %d\n", &n, &m);
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
		edge.pb(a);
	}
	direcao[1] = 1;
	if (!dfs(1)) {
		pr("NO\n"); return 0;
	}
	pr("YES\n");
	for(int i = 0; i < m; i++) {
		pr("%d", direcao[edge[i]]);
	}pr("\n");
 	return 0;
}
