#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, t, k;
char li[100010];
void reverse(int l, int r) {
	int m = (l+r)/2;
	for(int i = l; i <= m; i++) {
		char tmp = li[i];
		li[i] = li[r-(i-l)];
		li[r-(i-l)] = tmp;
	}
}
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d\n", &n, &k);
		vector<ii> resp;
		
		for(int i = 1; i <= n; i++) {
			li[i] = getchar();
		}
		for(int i = 1; i <= n;i+=2) {
			if (k > 1) {
				int f = 0;
				for(int j = i; j <= n; j++) {
					if (li[j] == '(') {f = j;break;}
				}
				reverse(i, f);
				resp.pb({i, f});
				for(int j = i+1; j <= n; j++) {
					if (li[j] == ')') {f = j;break;}
				}
				reverse(i+1, f);
				resp.pb({i+1, f});
				k--;
			} else {
				
				for(int k = i; k <= n; k++) {
					int f = 0;
					if (k-i <= n-k) {
						for(int j = k; j <= n; j++) {
							if (li[j] == '(') {f = j;break;}
						}
						resp.pb({k, f});
						reverse(k, f);
					}
				}
				
				break;
			}
		}
		pr("%d\n", (int)resp.size());
		for(int i = 0; i < (int) resp.size(); i++) {
			pr("%d %d\n", resp[i].first, resp[i].second);
		}
		
	}
	
	
 	return 0;
}
