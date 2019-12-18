#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 2010
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;
map<vector<ii>, int> mp;
int n, m;
//accum de tras pra frente
int grid[MAX][MAX];
int getrow(int r, int c) {
	int x = grid[r][MAX-1];
	x -= grid[r][c];
	if(r) {
		x -= grid[r-1][MAX-1];
		x += grid[r-1][c];
	}
	return x;
}
int getcol(int c, int r) {
	int x = grid[MAX-1][c];
	x -= grid[r][c];
	if(c) {
		x -= grid[MAX-1][c-1];
		x += grid[r][c-1];
	}
	return x;
}
int dpt[MAX][MAX][2];
// tipo == 0 : esquerda-direita / 1: cima-baixo
int dp(int r, int c, int tipo) {
	if(r == n-1) {
		if(tipo) return c == m-1;
		return (getrow(r, c)) ? 0 : 1;
	}
	if (c == m-1) {
		if(!tipo) return r == n-1;
		return (getcol(c, r)) ? 0 : 1;
	}
	if(dpt[r][c][tipo] == -1) {
		if (!tipo) {
			ll tmp = dp(r, c+1, tipo);
			if(getrow(r, c) != getrow(r, c+1)) tmp -= dp(r, m-1-getrow(r, c+1), !tipo);
			tmp += dp(r, c+1, !tipo);
			dpt[r][c][tipo] = ((tmp%MOD)+MOD)%MOD;
		} else {
			ll tmp = dp(r+1, c, tipo);
			if(getcol(c, r) != getcol(c, r+1)) tmp -= dp(n-1-getcol(c, r+1), c, !tipo);
			tmp += dp(r+1, c, !tipo);
			dpt[r][c][tipo] = ((tmp%MOD)+MOD)%MOD;
		}
	}
	return dpt[r][c][tipo];
}
int main(){
	sc("%d %d\n", &n, &m);
	if(n == 1 && m == 1) {
		pr("1\n");
		return 0;
	}
	memset(dpt, -1, sizeof dpt);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			grid[i][j] = (getchar() == 'R');
		}getchar();
	}
	for(int i = 0; i < MAX; i++) {
		for(int j = 0; j < MAX; j++) {
			if(i) grid[i][j]+= grid[i-1][j];
			if(j) grid[i][j]+= grid[i][j-1];
			if(i && j) grid[i][j] -= grid[i-1][j-1];
		}
	}

	pr("%lld\n", (dp(0, 0, 0)+dp(0, 0, 1))%MOD);

 	return 0;
}
