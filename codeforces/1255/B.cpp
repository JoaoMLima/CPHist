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


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;


int main(){
    int a, b, t, n, m;
	sc("%d", &t);
	while(t--) {
		
		sc("%d %d", &n, &m);
		int mini1 = 100000;
		int mini2 = 100000;
		int mini1i = 100000;
		int mini2i = 100000;
		int resp = 0;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			resp += 2*a;
			if(a < mini1) {
				mini2 = mini1;
				mini2i = mini1i;
				mini1 = a;
				mini1i = i+1;
			} else if (a < mini2) {
				mini2 = a;
				mini2i = i+1;
			}
		}
		if (m < n || n == 2) {
			pr("-1\n"); continue;
		}
		m -= n;
		pr("%d\n", resp + (mini1+mini2)*m);
		for(int i = 1; i < n; i++) {
			pr("%d %d\n", i, i+1);
		}
		pr("%d %d\n", n, 1);
		for(int i = 0; i < m; i++) {
			pr("%d %d\n", mini1i, mini2i);
		}

		
		
	}
	

	
 	return 0;
}
