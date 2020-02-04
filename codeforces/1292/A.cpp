#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
int p[200010];
int bit[3][200010];
int li[3][200010];
void update(int i, int j, int v) {
    while(i < 3) {
        int k = j;
        while(k < 200010) {
            bit[i][k] += v;
            k += k&(-k);
        }
        i += i&(-i);
    }
}
int query(int i, int j) {
    int s = 0;
    while(i) {
        int k = j;
        while(k) {
            s += bit[i][k];
            k -= k&(-k);
        }
        i -= i&(-i);
    }
    return s;
}
int queryUni(int i, int j) {
    int x = query(i, j);
    if (i > 1) x -= query(i-1, j);
    if (j > 1) x -= query(i, j-1);
    if (i > i && j > 1) x += query(i-1, j-1);
    return x;
}
int main() {
    int n, q, a, b;
    /*
    update(1, 2, 1);
    update(2, 4, 1);
    pr("%d\n", query(1, 2));
    pr("%d\n", query(2, 2));
    pr("%d\n", query(2, 3));
    pr("%d\n", query(1, 4));
    pr("%d\n", query(2, 4));
    pr("%d\n", query(1, 5));
    pr("%d\n", query(2, 5));
*/
    sc("%d %d", &n, &q);
    
    for(int i = 0; i < q; i++) {
        sc("%d %d", &a, &b);
        
        if (li[a][b]) {
            for(int j = -1; j <= 1; j++) {
                for(int k = -1; k <= 1; k++) {
                    if(j && a+j >= 1 && a+j <= 2 && b+k >= 1 && b+k <= n) {
                        int x = a+j, y = b+k;
                        if(li[x][y]) {
                            int d = min(a, x), e = min(b, y);
                            update(d, e, -1);
                        }
                    }
                }
            }
        } else {
            for(int j = -1; j <= 1; j++) {
                for(int k = -1; k <= 1; k++) {
                    if(j && a+j >= 1 && a+j <= 2 && b+k >= 1 && b+k <= n) {
                        int x = a+j, y = b+k;
                        if(li[x][y]) {
                            int d = min(a, x), e = min(b, y);
                            update(d, e, 1);
                        }
                    }
                }
            }
        }
        if (query(2, n)) pr("No\n");
        else pr("Yes\n");
        li[a][b] = !li[a][b];
    }
    return 0;
}