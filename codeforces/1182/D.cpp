#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
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
 
vi g[100010];
int visited[100010];
int subtree[100010];
int degreeByDist[100010];
int dfs(int i) {
	subtree[i] = 1; visited[i] = 1;
	for(int adj : g[i]) {
		if (!visited[adj])
			subtree[i] += dfs(adj);
	}
	return subtree[i];
}
 
int dfs2(int i, int dist) {
	visited[i] = 1;
	if (degreeByDist[dist] == -1) degreeByDist[dist] = g[i].size();
	else if (degreeByDist[dist] != g[i].size()) return 0;
 
	for(int adj : g[i]) {
		if (!visited[adj] && !dfs2(adj, dist+1)) return 0;
	}
	return 1;
}
map<int, int> distQuant;
map<int, int> distNode;
void insert(int dist) {
	if (distQuant.count(dist)) {
		distQuant[dist]++;
	} else {
		distQuant[dist] = 1;
	}
}
ii dfs3(int i, int dist) {
	visited[i] = 1;
	if (dist == 0) {
		map<int, int> m;
		for(int adj : g[i]) {
			ii j = dfs3(adj, dist+1);
			if (j.fi != -1) {
				insert(j.se);
				distNode[j.se] = j.fi;
			}
		}
	} else {
		if (g[i].size() == 1) {
			return {i, dist};
		} else if (g[i].size() == 2) {
			for(int adj : g[i]) {
				if (!visited[adj]) {
					 return dfs3(adj, dist+1);
				}
			}
		}
		return {-1, 0};
	}
}
 
int main(){
	memset(degreeByDist, -1, sizeof degreeByDist);
	sc("%d", &n);
	for(int i = 0; i < n-1; i++) {
		sc("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	if (n <= 2) {pr("1\n"); return 0;}
	bool changed = true;
	dfs(1);
	memset(visited, 0, sizeof visited);
	int node = 1;
	while(changed) {
		changed = false;
		for(int adj : g[node]) {
			if(subtree[adj] < subtree[node] && subtree[adj] > n / 2) {
				node = adj;
				changed = true; break;
			}
		}
	}
	//trace("node:", node);
	if (!dfs2(node, 0)) {
		memset(visited, 0, sizeof visited);
		ii j = dfs3(node, 0);
		if (distQuant.size() > 2) {
			pr("-1\n"); return 0;
		}
		for(map<int, int>::iterator it = distQuant.begin(); it != distQuant.end(); it++) {
			if (it->second == 1) {
				node = distNode[it->first];
				break;
			}
		}
		memset(degreeByDist, -1, sizeof degreeByDist);
		memset(visited, 0, sizeof visited);
		if (!dfs2(node, 0)) {
			pr("-1\n");
		} else {
			pr("%d\n", node);
		}
		
	} else {
		pr("%d\n", node);
	}
 
	
 
 	return 0;
}
