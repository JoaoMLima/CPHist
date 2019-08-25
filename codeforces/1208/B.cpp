#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
 
typedef long long ll;
typedef pair<int, int> ii;
 
int li[20010];
int n, a;
int accum[2000][2000];
int accumR[2000][2000];
int main(){
	// a - b - a^b - a - b
	sc("%d", &n);
	int atual = 0;
	map<int, int> ma;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if(!ma.count(a)) {
			ma[a] = atual++;
		}
		li[i] = ma[a];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != 0) {
				accum[i][j] = accum[i-1][j];
			}
		}
		accum[i][li[i]]++;
	}
	int p = 1;
	for(int j = 0; j < n; j++) {
		if (accum[n-1][j] > 1) p = 0;
	}
	if(p) {
		pr("0\n"); return 0;
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < n; j++) {
			if(i != n-1) {
				accumR[i][j] = accumR[i+1][j];
			}
		}
		accumR[i][li[i]]++;
	}
	int res = n-1;
	for(int i = 0; i < n; i++) {
		int l = i, r = n-1;
		int tot[n];
		while (l <= r && l <= n-1) {
			int m = (l+r)/2;
			int ok = 1;
			memset(tot, 0, sizeof tot);
			if(i > 0) {
				for(int j = 0; j < n; j++) {
					tot[j] += accum[i-1][j];
				}
			}
			if(m < n-1) {
				for(int j = 0; j < n; j++) {
					tot[j] += accumR[m+1][j];
				}
			}
			for(int j = 0; j < n; j++) {
				if(tot[j] > 1) ok = 0;
			}
			//pr("%d %d %d\n", i, m, ok);
			if(!ok) {
				l = m+1;
			} else {
				r = m-1;
			}
		}
		if(l != n) {
			
			memset(tot, 0, sizeof tot);
			int ok = 1;
			if(i > 0) {
				for(int j = 0; j < n; j++) {
					tot[j] += accum[i-1][j];
				}
			}
			if(l < n-1) {
				for(int j = 0; j < n; j++) {
					tot[j] += accumR[l+1][j];
				}
			}
			for(int j = 0; j < n; j++) {
				if(tot[j] > 1) ok = 0;
			}
			//pr("%d %d %d %d\n", l, r, i, ok);
			if(ok) res = min(res, l-i+1);
			else res = min(res, r-i+1);
		}
	}
	pr("%d\n", res);
	
	//sc("%d %d", &, &);
	//sc("%d %d %d", &, &, &);
	//sc("%d %d %d %d", &, &, &, &);
	//for (int i = 0; i < ; i++)
 	return 0;
}