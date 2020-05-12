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
int cri[100010];
int li[100010];
int r[100010];
int main(){
	int t;
	sc("%d", &t);
	/*
	vector<int> primes;
	for(int i = 2; i <= 100000; i++) {
		cri[i] = 1;
	}
	for(int i = 2; i <= 100000; i++) {
		if (cri[i]) {
			primes.pb(i);
			if (i < 1000) {
				for(int j = i*i; j <= 100000; j+= i) {
					cri[i] = 0;
				}
			}
		}
	}*/
	while(t--) {
		sc("%d", &n);
		int resp = 1;
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
			r[i] = 1;
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 2; j <= n; j++) {
				if (j * i > n) break;
				if (li[j*i] > li[i]) {
					r[j*i] = max(r[j*i], r[i]+1);
					resp = max(resp, r[j*i]);
				}
			}
		}
		pr("%d\n", resp);
	}
 	return 0;
}
