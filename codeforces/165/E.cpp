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

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

int n, m, a, b, c;
int l[1<<22];
int li[1000001];
int dp(int i) {
    if(l[i]) return l[i];
    int bi = 1;
    int r = -1;
    for(int j = 0; j < 22; j++) {
        if(bi & i) {
            r = max(r, dp(i ^ bi));
        }
        bi <<=1;
    }
    l[i] = r;
    return r;
}

int main(){
    memset(l, 0, sizeof l);
    l[0] = -1;
	sc("%d\n", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", li+i);
        l[li[i]] = li[i];
    }
    int mask = (1<<22)-1;
    dp(mask);
    for(int i = 0; i < n; i++) {
        pr("%d ", dp((~(li[i]))&mask));
    }

 	return 0;
}