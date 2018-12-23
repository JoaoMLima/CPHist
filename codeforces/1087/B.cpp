#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9
int n, m, a = 0, b = 0;

int main(){
    sc("%d %d\n", &n, &m);
    for(int i = 1; i < 1000000000; i++) {
        b++;
        if(b == m) {a++; b = 0;}
        if (a * b == n) {
            pr("%d\n", i);
            return 0;
        }
    }
 	return 0;
}