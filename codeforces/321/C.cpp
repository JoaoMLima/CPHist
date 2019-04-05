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



//Centroid Decomposition
vi g[100001];
vi centroidG[100001];
int visited[100001];
bool marked[100001];
int subtree[100001];
int dfsId = 0;
int dfs(int i) {
	subtree[i] = 1; visited[i] = dfsId;
	for(int adj : g[i]) {
		if (visited[adj] != dfsId && !marked[adj])
			subtree[i] += dfs(adj);
	}
	return subtree[i];
}
int getCentroid(int node) {
	dfsId++;
	int sz = dfs(node);
	bool change = true;
	while(change) {
		change = false;
		for(int adj : g[node]) {
			if(!marked[adj] && subtree[adj] < subtree[node] && subtree[adj] > sz / 2) {
				node = adj;
				change = true; break;
			}
		}
	}
	marked[node] = true;
	for(int adj : g[node]) {
		if(!marked[adj]) {
			// To make a undirected tree
			// int cent = getCentroid(adj);
			// centroidG[node].pb(cent);
			// centroidG[cent].pb(node);
			centroidG[node].pb(getCentroid(adj));
		}
	}
	return node;
}

// To use on main
// memset(marked, false, sizeof marked);
// memset(visited, 0, sizeof visited);
// int root = getCentroid(1);

//End here
char h[100001];
void dfs2(int i) {
	visited[i] = dfsId;
	for(int j = 0; j < (int)centroidG[i].size(); j++) {
		h[centroidG[i][j]] = h[i]+1;
		dfs2(centroidG[i][j]);
	}
}


int main(){
	memset(marked, false, sizeof marked);
	memset(visited, 0, sizeof visited);
	sc("%d", &n);
	for(int i = 0; i < n-1; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	int root = getCentroid(1);
	
	h[root] = 'A';
	dfsId++;
	dfs2(root);
	for(int i = 1; i <= n; i++) {
		pr("%c ", h[i]);
	}
	pr("\n");
}
