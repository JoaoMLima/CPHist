#include <bits/stdc++.h>
using namespace std;
#define pr printf
#define sc scanf
#define fi first
#define se second

typedef pair<int, int> ii;
int n, col, a, b, c, r, d, q;
char ch;
char m[1001][1001];
ii p[1001][1001];
int ranked[1001][1001];
int total[1001][1001];
ii find(int i, int j) {
    if (p[i][j] == make_pair(i, j)) { return {i, j};}
    return find(p[i][j].fi, p[i][j].se);
}
void uni(int i1, int j1, int i2, int j2) {
    ii p1 = find(i1, j1), p2 = find(i2, j2);
    if (p1 != p2) {
        //pr("%d %d %d %d\n", p1.fi, p1.se, p2.fi, p2.se);
         //pr("%d %d %d %d %d %d\n", p1.fi, p1.se, p2.fi, p2.se, total[p1.fi][p1.se], total[p2.fi][p2.se]);
        if (ranked[p1.fi][p1.se] > ranked[p2.fi][p2.se]) {
            p[p2.fi][p2.se] = {p1.fi, p1.se};
            total[p1.fi][p1.se] += total[p2.fi][p2.se];
        } else {
            p[p1.fi][p1.se] = {p2.fi, p2.se};
            total[p2.fi][p2.se] += total[p1.fi][p1.se];
        }
        if (ranked[p1.fi][p1.se] == ranked[p2.fi][p2.se]) {
            ranked[p2.fi][p2.se]++;
        }
    }
}
int main() {
    sc("%d %d %d\n", &n, &col, &q);
    memset(ranked, 0, sizeof ranked);
    memset(total, 0, sizeof total);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < col; j++) {
            p[i][j] = {i, j};
            m[i][j] = getchar();
        }
        getchar();
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < col; j++) {
            if(m[i][j] == '.') {
                if (m[i-1][j] == '*') {total[i][j]++;}
                if (m[i+1][j] == '*') {total[i][j]++;}
                if (m[i][j-1] == '*') {total[i][j]++;}
                if (m[i][j+1] == '*') {total[i][j]++;}
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < col; j++) {
            if (m[i][j] == '.') {
                if (m[i+1][j] == '.') {
                    uni(i, j, i+1, j);
                }
                if (m[i][j+1] == '.') {
                    uni(i, j, i, j+1);
                }
            }
        }
    }
    for(int i = 0; i < q; i++) {
        sc("%d %d", &a, &b);
        ii pai = find(a-1, b-1);
        //pr("%d %d %d %d\n", a, b, pai.fi, pai.se);
        pr("%d\n", total[pai.fi][pai.se]);
    }
    return 0;
}