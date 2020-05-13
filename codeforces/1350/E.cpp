#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int n, m, a, b; ll c;
int qt[2010][2010];
int ig[1010][1010];
int cor[1010][1010];
void update(int i, int j) {
	int ma = i-j, se = (1001-i)-j;
	qt[ma+1005][se+1005]++;
}
int dist(int i, int j) {
	if (ig[i][j]) return 0;
	int ma = (i-j)+1005, se = (1001-i)-j+1005;
	int resp = 100000;
	int l = 1, r = 10000;
	while(l <= r) {
		int mid = (l+r)/2;
		int mal = max(0, ma-mid), mar = min(2010-1, ma+mid);
		int sel = max(0, se-mid), ser = min(2010-1, se+mid);
		int qtd = qt[mar][ser];
		if (mal > 0) qtd -= qt[mal-1][ser];
		if (sel > 0) qtd -= qt[mar][sel-1];
		if (mal > 0 && sel > 0) qtd += qt[mal-1][sel-1];
		if (qtd) {
			r = mid-1;
			resp = mid;
		} else {
			l = mid+1;
		}
	}
	return resp;
}
int main(){
	int t;
	sc("%d %d %d\n", &n, &m, &t);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cor[i][j] = getchar()-'0';
		}getchar();
	}
	int tembloco = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			int igual = 0;
			if (i > 1 && cor[i][j] == cor[i-1][j]) igual = 1;
			if (i < n && cor[i][j] == cor[i+1][j]) igual = 1;
			if (j > 1 && cor[i][j] == cor[i][j-1]) igual = 1;
			if (j < m && cor[i][j] == cor[i][j+1]) igual = 1;
			//pr("eae %d %d\n", cor[i][j], igual);
			if (igual) {
				ig[i][j] = 1;
				update(i, j);
				tembloco = 1;
			}
		}
	}
	for(int i = 0; i < 2010; i++) {
		for(int j = 0; j < 2010; j++) {
			if (i > 0) qt[i][j] += qt[i-1][j];
			if (j > 0) qt[i][j] += qt[i][j-1];
			if (i > 0 && j > 0) qt[i][j] -= qt[i-1][j-1];
		}
	}
/*
	for(int k = 0; k <= 4; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				ll x = cor[i][j], y = dist(i, j), z = k;
				if (y > z) pr("%d", cor[i][j]);
				else pr("%lld", (x ^ y ^ z) & 1LL);
			}pr("\n");
		}pr("\n");
	}
	*/
	while(t--) {
		sc("%d %d %lld\n", &a, &b, &c);
		if (!tembloco) {
			pr("%d\n", cor[a][b]);
		} else {
			ll x = cor[a][b], y = dist(a, b), z = c;
			if (y > z) pr("%d\n", cor[a][b]);
			else pr("%lld\n", (x ^ y ^ z) & 1LL);
		}
	}
 	return 0;
}
