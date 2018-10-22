#include <bits/stdc++.h>
using namespace std;
#define pr printf
#define sc scanf
typedef pair<int, int> ii;
int n, a, b, c, r, d;
int accu[2002];
int resp[2002];
int li[2002];
int main() {
    sc("%d %d", &r, &d);
    sc("%d", &n);
    int cont = 0;
    for(int i = 0; i < n; i++) {
        sc("%d %d %d", &a, &b, &c);
        if (hypot(a, b) - c >= r-d && hypot(a, b)+c <= r) {
            cont++;
        }
    }
    pr("%d\n", cont);
    
    return 0;
}