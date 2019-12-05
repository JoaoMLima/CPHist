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
#define MAX 400010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int li[MAX];
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
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		sort(li, li+n, greater<int>());
		int i;
		int g = 1, s = -1, b = -1;
		for(i = 1; i < n; i++) {
			if (li[i] != li[i-1]) {s = 1;i++; break;}
			else g++;
		}
		//pr("i: %d\n", i-2);
		for(; i < n; i++) {
			if (li[i] != li[i-1] && s > g) {b = 1; i++; break;}
			else s++;
		}
		//pr("i: %d\n", i-2);
		for(; i <= n/2; i++) {
			if (li[i] != li[i-1]) {b = (i)-(s+g);}
		}
		if (b <= g || s <= g) {
			pr("0 0 0\n");
		} else {
			pr("%d %d %d\n", g, s, b);
		}

	}
 	return 0;
}
