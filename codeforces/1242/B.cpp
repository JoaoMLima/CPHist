#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;
int p[MAX];
int find(int a) {
	if (p[a] == a) return a;
	p[a] = find(p[a]);
	return p[a];
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (rand()&1) p[a] = b;
	else p[b] = a;
}
set<ii> edges;
set<int> toprocess;
void process(int v) {
	/*
	cout << "toprocess(" << v << ")" ;
	for(int x : toprocess) {
		cout << " " << x;
	}cout << endl;
	*/
	vector<int> nexts;
	for(int x : toprocess) {
		if (!edges.count({min(v, x), max(v, x)})) {
			//pr("uni: %d %d\n", v, x);
			uni(v, x);
			nexts.pb(x);
		}
	}
	for(int x: nexts) {
		toprocess.erase(x);
	}
	for(int x : nexts) {
		process(x);
	}

}



int main(){
	int n, m, a, b, c;
	for(int i = 0; i < MAX; i++) p[i] = i;

	sc("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		toprocess.insert(i);
	}
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		edges.insert({min(a, b), max(a, b)});
	}
	
	for(int i = 1; i <= n; i++) {
		if(toprocess.count(i)) {
			toprocess.erase(i);
			process(i);
		}
	}
	
	set<int> cmp;
	for(int i = 1; i <= n; i++) {
		cmp.insert(find(i));
	}
	pr("%d\n", (int)cmp.size()-1);
	return 0;
}
