#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int n, t, x, a, b;
int main(){
	cin >> t;
	while(t--) {
		cin >> n >> x;
		int qtdx = 0;
		for(int i = 0; i < n-1; i++) {
			cin >> a >> b;
			if (a == x || b == x) {
				qtdx++;
			}
		}
		if (qtdx <= 1) pr("Ayush\n");
		else if ((n-1) % 2 == 1) pr("Ayush\n");
		else pr("Ashish\n");
	}
 	return 0;
}
