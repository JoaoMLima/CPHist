#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c;
int qtd[2010];
int val[2010];
int st[2010];
ordered_set o_set;
vector<int> g[2010];
int dfs(int v) {
	st[v] = 1;
	for(int x : g[v]) {
		st[v] += dfs(x);
	}
	return st[v];
}

int dfs2(int v) {
	if (qtd[v] > st[v] -1) return 0;
	val[v] = *(o_set.find_by_order(qtd[v]));
	o_set.erase(val[v]);
	for(int x : g[v]) {
		if (!dfs2(x)) return 0;
	}
	return 1;
}

int main(){
	
	sc("%d", &n);
	int root = -1;
	for(int i = 1; i <= n; i++) {
		o_set.insert(i);
	}
	for(int i = 1; i <= n; i++) {
		sc("%d %d", &a, &b);
		if (a != 0) g[a].pb(i);
		else root = i;
		qtd[i] = b;
	}
	dfs(root);
	if (!dfs2(root)) {
		pr("NO\n");
	} else {
		pr("YES\n");
		for(int i = 1; i <= n; i++) {
			if(i > 1) pr(" ");
			pr("%d", val[i]);
		}
	}pr("\n");

 	return 0;
}
