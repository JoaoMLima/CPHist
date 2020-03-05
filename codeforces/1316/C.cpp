#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, p, a;
    int i1 = -1, i2 = -1;
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a);
        if (a % p && i1 == -1) {
            i1 = i;
        }
    }
    for(int i = 0; i < m; i++) {
        scanf("%d", &a);
        if (a % p && i2 == -1) {
            i2 = i;
        }
    }
    printf("%d\n", i1+i2);
}