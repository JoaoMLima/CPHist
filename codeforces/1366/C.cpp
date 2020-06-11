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

int n, t, a, b, c, x, m;
int qt[62][2];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &n, &m);
		for(int i = 0; i < n; i++) {
			for(int j = 0;j < m; j++) {
				qt[i+j][1] = 0;
				qt[i+j][0] = 0;
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0;j < m; j++) {
				sc("%d", &a);
				qt[i+j][0] += !a;
				qt[i+j][1] += a;
			}
		}
		int r = 0;
		int x = (n+m-1)/2;
		//pr("%d %d\n", n+m-1, x);
		for(int i = 0; i < x; i++) {
			r += min(qt[i][0]+qt[n+m-2-i][0], qt[i][1]+qt[n+m-2-i][1]);
		}
		
		pr("%d\n", r);
		
		
	}
	
 	return 0;
}
