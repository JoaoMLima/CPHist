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

int n, t, a, b,m;
int main(){
	sc("%d", &t);
	while(t--) {
		
		sc("%d %d", &n, &m);
		vector<int> r(n, 0);
		vector<int> c(m, 0);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				sc("%d", &a);
				if(a) {
					r[i] = 1;
					c[j] = 1;
				}
			}
		}
		int a = 0, b = 0;
		for(int i = 0; i < n; i++) {
			if (!r[i])a++;
		}
		for(int i = 0; i < m; i++) {
			if (!c[i])b++;
		}
		pr((min(a, b) % 2) ? "Ashish\n": "Vivek\n");
	}
 	return 0;
}
