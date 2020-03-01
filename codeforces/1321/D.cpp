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

int n, m, k, a, b, c;
vector<int> g[200010];
set<int> s[200010];
int d[200010];
int vi[200010];
vector<int> vec;
int main(){
	for(int i = 0; i < 200010; i++) {d[i] = 1000000;}
	sc("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		g[b].pb(a);
	}
	sc("%d", &k);
	for(int i = 0; i < k; i++) {
		sc("%d", &a);
		vec.pb(a);
	}
	d[vec[k-1]] = 0;
	queue<int> q;
	q.push(vec[k-1]);
	vi[vec[k-1]] = 1;
	while(!q.empty()) {
		int v = q.front();q.pop();
		for(int x : g[v]) {
			if (d[x] >= d[v]+1) {
				d[x] = d[v]+1;
				s[x].insert(v);
				if (!vi[x]) {
					q.push(x);
				}
				vi[x] = 1;
			}
		}
	}
	int mini = 0;
	int maxi = 0;
	/*
	for(int i = 1; i <= n; i++) {
		pr("d[%d]: %d\n", i, d[i]);
		for(int x : s[i]) {
			pr("%d ", x);
		}pr("\n");
	}*/
	for(int i = 0; i < k-1; i++) {
		if (s[vec[i]].count(vec[i+1])) {
			if ((int)s[vec[i]].size() > 1) {
				maxi += 1;
			}
		} else {
			maxi +=1; mini += 1;
		}
	}
	pr("%d %d\n", mini, maxi);
	
 	return 0;
}
