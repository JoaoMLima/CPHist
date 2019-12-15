#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, m, a, b, c, x;
int li[60][60];
int rowl[60];
int colu[60];
int rowr[60];
int cold[60];

int main(){
	int t;
	sc("%d\n", &t);
	while(t--) {
		n = 0;
		int ok = 0;
		sc("%d %d\n", &n, &m);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				li[i][j] = (getchar() == 'A');
				if(li[i][j]) ok++;
			}getchar();
		}
		
		if(!ok) {pr("MORTAL\n");continue;}
		if(ok == n*m) {
			pr("0\n");continue;
		}
		int res = 4;
		for(int i = 0; i < n; i++) {
			rowl[i] = 0;
			rowr[i] = 0;
			for(int j = 0; j < m; j++) {
				if (!li[i][j]) break;
				else rowl[i]++;
			}
			if(rowl[i]) res = min(res, 3);
			if(rowl[i] == m) res = min(res, 2);
			for(int j = m-1; j >= 0; j--) {
				if (!li[i][j]) break;
				else rowr[i]++;
			}
			if(rowr[i]) res = min(res, 3);
		}
		for(int j = 0; j < m; j++) {
			colu[j] = 0;
			cold[j] = 0;
			for(int i = 0; i < n; i++) {
				if (!li[i][j]) break;
				else colu[j]++;
			}
			if(colu[j] == n) res = min(res, 2);
			if(colu[j]) res = min(res, 3);
			for(int i = n-1; i >= 0; i--) {
				if (!li[i][j]) break;
				else cold[j]++;
			}
			if(cold[j]) res = min(res, 3);
		}
		if(rowl[0] == m || rowl[n-1] == m || colu[0] == n || colu[m-1] == n) {
			res = min(res, 1);
		}
		if(rowl[0] || rowr[0] || rowl[n-1] || rowr[n-1] || colu[0] || cold[0] || colu[m-1] || cold[m-1]) {
			res = min(res, 2);
		}
		if(rowl[0] + rowr[n-1] >= m || rowl[n-1] + rowr[0] >= m || colu[0] + cold[m-1] >= n || colu[m-1] + cold[0] >= n) {
			res = min(res, 2);
		}
		pr("%d\n", res);
	}
 	return 0;
}
