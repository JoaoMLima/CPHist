#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c;
vector<int> g[100010];
int li[100010];
int maxi = 0;

int fli = 0, flp = 0;
int dfs(int v, int p, int par) {
	if ((int)g[v].size() == 1) {
		if (par&1)fli++;
		else flp++;
		return 1;
	}
	int ch = 0;
	for(int x : g[v]) {
		if (x != p) ch += dfs(x, v, par+1);
	}
	if (ch > 1) maxi -= ch-1;
	return 0;
}

int main(){
	sc("%d", &n);
	for(int i = 0; i < n-1; i++) {
		sc("%d %d", &a, &b);
		li[a]++;
		li[b]++;
		g[a].pb(b);
		g[b].pb(a);
	}
	maxi = n-1;
	int root = 0;
	for(int i = 1; i <= n; i++) {
		if (li[i] > 1) {root = i; break;}
	}
	dfs(root, -1, 0);
	int mini = 1;
	if (flp > 0 && fli > 0) mini = 3;

	pr("%d %d\n", mini, maxi);


	
	//if (todas folhas estão em profundidade com mesma paridade) -> min = 1
	//else -> min = 3
	
	//coloca um cara que não é folha como raiz
	//todos os filhos folha de um mesmo cara podem ser reduzidos a um unico filho
 	return 0;
}
