#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010;

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c, m;
int li[1010][1010];
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d %d %d\n", &n, &m, &a, &b);
		int r = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++){
				li[i][j] = (getchar() == '*');
			}getchar();
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++){
				if (j < m-1 && !li[i][j] && !li[i][j+1] && a+a > b) {
					r += b;
					li[i][j] = 1;
					li[i][j+1] = 1;
				} else if (!li[i][j]) {
					r += a;
					li[i][j] = 1;
				}
			}
		}
		pr("%d\n", r);
	}
	
 	return 0;
}
