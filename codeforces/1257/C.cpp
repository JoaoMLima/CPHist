#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define INF 1000000000

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int main(){
    int t, n, x, a, b, y;
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		map<int, int> ma;
		int resp = INF;
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (ma.count(a)) {
				resp = min(resp, i-ma[a]+1);
				ma[a] = i;
			} else {
				ma[a] = i;
			}
		}
		if (resp == INF) pr("-1\n");
		else pr("%d\n", resp);
	}
 	return 0;
}
