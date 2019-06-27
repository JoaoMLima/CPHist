#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define MAXN 200020
int n, k, tempK, atual = 0;
double accumTokens[MAXN];
double accumInvTokens[MAXN];
double accumTokenDivisions[MAXN];
double dpt[2][MAXN];

double getCusto(int i, int j) {
    return accumTokenDivisions[j] - accumTokenDivisions[i-1]
        - ((accumInvTokens[j+1] - accumInvTokens[n+1]) * (accumTokens[j] - accumTokens[i-1]));
}

void dp(int l, int r, int OPmin, int OPmax) {
    if (l > r) return;

    int m = (l+r)/2;
    double mini = DBL_MAX;
    int op = m;

    for(int i = max(OPmin, tempK-1); i <= min(OPmax, m-1); i++) {
        if (dpt[!atual][i] + getCusto(i+1, m) < mini) {
            mini = min(mini, dpt[!atual][i] + getCusto(i+1, m));
            op = i;
        }
    }
    dpt[atual][m] = mini;
    dp(l, m-1, OPmin, op);
    dp(m+1, r, op, OPmax);
}

void getAndParseInput() {
    for(int i = 1; i <= n; i++) {
        sc("%lf", accumTokens+i);
    }
    for(int i = n; i >= 0; i--) {
        accumInvTokens[i] = 1/accumTokens[i] + accumInvTokens[i+1];
    }
    for(int i = 1; i <= n+1; i++) {
        accumTokenDivisions[i] = accumTokenDivisions[i-1] + accumTokens[i]*accumInvTokens[i];
    }
    for(int i = 1; i <= n+1; i++) {
        accumTokens[i] += accumTokens[i-1];
    }
}

int main(){
	sc("%d %d", &n, &k);

    getAndParseInput();

    for(int i = 1; i <= n; i++) dpt[!atual][i] = getCusto(1, i); // Caso base
    for(int i = 2; i <= k; i++) {
        tempK = i;
        dp(1, n, 1, n);
        atual = !atual;
    }

    pr("%.15lf\n", dpt[!atual][n]);
 	return 0;
}