#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000
#define MAX 200010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int pos[MAX];
/*
int find(int a) {
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

void uni(int a, int b) {
	a = find(a); b = find(b);
	if (rand()&1) p[a] = b;
	else p[b] = a;
}*/
int t, n, a;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 1; i <= n; i++) {
			sc("%d", &a);
			pos[a] = i;
		}
		pr("1");
		int mini = pos[1];
		int maxi = pos[1];
		for(int i = 2; i <= n; i++) {
			mini = min(mini,pos[i]);
			maxi = max(maxi, pos[i]);
			if(maxi-mini == i-1) pr("1");
			else pr("0");
		}
		pr("\n");
	}
 	return 0;
}
