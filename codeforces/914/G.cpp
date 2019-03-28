#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 1<<17
#define MAXN 1<<17
#define LOGN 17
#define mod 1000000007
#define modL 1000000007LL
#define md(x) ((((x) % mod) + mod) % mod)
#define mdL(x) ((((x) % modL) + modL) % modL)
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

vector<ll> other_convolution(vector<ll> a) {
    vector<ll> ret(MAXN);
    for(int mask = 0; mask < MAXN; mask++)
        for(int subset = mask;; subset = (subset-1) & mask) {
            ret[mask] = (ret[mask] + a[subset]*a[mask^subset]) % modL;
            if(!subset) break;
        }
    return ret;
}

int T[3][2][2][2] = {
    { { {1,  1}, {1, -1} }, { {1,  1}, {1, -1} } }, /// xor
    { { {0,  1}, {1,  1} }, { {-1, 1}, {1,  0} } }, /// and
    { { {1,  1}, {1,  0} }, { {0,  1}, {1, -1} } }  /// or
};
 
void FFT(vector<ll> &a, int op, bool inverse = false) {
    int u1 = T[op][inverse][0][0], v1 = T[op][inverse][0][1];
    int u2 = T[op][inverse][1][0], v2 = T[op][inverse][1][1];
 
    for(int b = 0; b < LOGN; b++)
        for(int i = 0; i < MAXN; i++)
            if((i & (1 << b)) == 0) {
                ll u = a[i], v	 = a[i + (1 << b)];
                ll a1 = u*u1 + v*v1, a2 = u*u2 + v*v2;
                a[i]            = (a1 < 0LL) ? a1 + modL : ((a1 >= modL) ? a1 - modL : a1);
                a[i + (1 << b)] = (a2 < 0LL) ? a2 + modL : ((a2 >= modL) ? a2 - modL : a2);
            }
 
	if (op == 0 && inverse)
		for (int i=0; i<a.size(); i++)
            a[i] = a[i] * 742744451LL % modL;
}
 
/// op is 0 for XOR, 1 for AND, 2 for OR
vector<ll> convolution(vector<ll> a, vector<ll> b, int op) {
    FFT(a, op, false);
    FFT(b, op, false);
    for(int i=0; i<a.size(); i++)
        a[i] = a[i] * b[i] % modL;
    FFT(a, op, true);
    return a;
}

vector<ll> vp0(maxn, 0LL);
vector<ll> vp1;
vector<ll> vp2;
vector<ll> vp3;
int fib[maxn];
int dp[17][3][maxn];

int main(){
    fib[0] = 0; fib[1] = 1;
    for(int i = 2; i < maxn; i++) {
        fib[i] = (fib[i-1]+fib[i-2] >= mod) ? (fib[i-1]+fib[i-2] - mod) : (fib[i-1]+fib[i-2]);
    }
	sc("%d", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        vp0[a]++;
    }
    vp1 = other_convolution(vp0);
    vp2 = convolution(vp0, vp0, 0);
    for(int i = 0; i < maxn; i++) {
        vp0[i] = vp0[i] * (fib[i]+0LL) % modL;
        vp1[i] = vp1[i] * (fib[i]+0LL) % modL;
        vp2[i] = vp2[i] * (fib[i]+0LL) % modL;
    }

    ll r = 0LL;
    for(int i = 0; i < LOGN; i++) {
        vector<ll> va(maxn, 0LL);
        vector<ll> vb(maxn, 0LL);
        vector<ll> vc(maxn, 0LL);
        vector<ll> vd(maxn);
        for(int j = 0; j < maxn; j++) {
            if(j&(1<<i)) {
                va[j^(1<<i)] = vp1[j];
                vb[j^(1<<i)] = vp0[j];
                vc[j^(1<<i)] = vp2[j];
            }
        }
        vd = convolution(va, convolution(vb, vc, 1), 1);
        r = (r + vd[0]) % modL;
    }
    pr("%lld\n", r);
 	return 0;
}