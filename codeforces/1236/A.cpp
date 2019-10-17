#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define pb push_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;


int main() {
    int t, a, b, c;
    sc("%d", &t);
    while (t--) {
        sc("%d %d %d", &a, &b, &c);
        int r = 0;
        r += (min(2*b, c)/2)*3;
        b -= (r/3);
        r += (min(2*a, b)/2)*3;
        pr("%d\n", r);
    }
    return 0;
}