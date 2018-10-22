#include <bits/stdc++.h>
using namespace std;
#define pr printf
#define sc scanf
typedef pair<int, int> ii;
int n, a, b, c;
int accu[2002];
int resp[2002];
int li[2002];
int main() {
    sc("%d\n", &n);
    memset(accu, 0, sizeof accu);
    memset(resp, 0, sizeof resp);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        li[i] = a;
        accu[a]++;
    }
    
    for(int i = 1999; i >= 0; i--) {
        accu[i] = accu[i] + accu[i+1];
    }
    pr("%d", accu[li[0]+1]+1);
    for(int i = 1; i < n; i++) {
        //pr("%d %d\n", li[i], accu[li[i]]);
        pr(" %d", accu[li[i]+1]+1);
    }
    printf("\n");
    return 0;
}