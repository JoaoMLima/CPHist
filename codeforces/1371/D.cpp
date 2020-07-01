#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int  t, n, k, m,  a, b, c, r;
int grid[307][307];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &k);
		if (k % n == 0) pr("0\n");
		else pr("2\n");
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				grid[i][j] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			if (!k) break;
			for(int j = 0; j < n; j++) {
				if (!k) break;
				//cout << j <<  " " << (i+j)%n << endl;
				//pr("%d %d\n", j, i+)
				grid[j][(i+j)%n] = 1;
				k--;
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				pr("%d", grid[i][j]);
			}pr("\n");
		}
	}
 	return 0;
}
