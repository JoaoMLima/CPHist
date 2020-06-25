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

int n, t, a, b, c;
ll get(ll qtd) {
	ll x = qtd%9;
	for(int i = 0; i < qtd/9; i++) {
		x = x*10+9;
	}
	return x;
}
ll get(ll qtd, ll l, ll r) {
	if (qtd < 0) return -1;
	ll mini = 1000000000000000000LL;
	for(int i = 0; i <= 8; i++) {
		int falta = qtd-(l*i+r*(i+1));
		if ( falta >= 0 && falta % (l+r) == 0) {
			mini = min(mini, get(falta/(l+r))*10+i);
		}
	}
	int falta = qtd-(l*9);
	if ( falta >= 0) {
		ll tmp = get(falta, l, r);
		if (tmp != -1) {
			mini = min(mini, tmp*10+9);
		}
	}
	if (mini != 1000000000000000000LL) return mini;
	return -1;

}
ll resp[157][10];

int main(){
	memset(resp, -1, sizeof resp);
	for(int i = 1; i <= 150; i++) {
		for(int j = 0; j <= 9; j++) {
			for (int k = 0; k <= 9; k++) {
				if (j+k <= 9) {
					int falta = i-((k+j+k)*(j+1))/2;
					if (falta >= 0 && falta % (j+1) == 0) {
						ll re = get(falta/(j+1))*10LL+k;
						if (resp[i][j] == -1) resp[i][j] = re;
						else resp[i][j] = min(resp[i][j], re);
					}
				} else {
					int r2 = (k+j)%10;
					int falta = i-((k+9)*(9-k+1))/2-((0+r2)*(r2+1))/2;
					if (falta >= 0) {
						ll tmp = get(falta, 9-k+1, r2-0+1);
						if (tmp != -1) {
							if (resp[i][j] == -1) resp[i][j] = tmp*10+k;
							else resp[i][j] = min(resp[i][j], tmp*10+k);
						}
					}
				}
			}
			//cout << resp[i][j] << " ";
		}//cout << endl;
	}
	
	sc("%d\n", &t);

	while(t--) {
		sc("%d %d", &a, &b);
		pr("%lld\n", resp[a][b]);
		


	}
 	return 0;
}
