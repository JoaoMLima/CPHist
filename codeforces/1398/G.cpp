#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}

const int mod = 7340033;
const int root = 5;
const int root_1 = 4404020;
const int root_pw = 1 << 20;

void fft(vector<int> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = invmod(n, mod);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> prefixos;
vector<int> sufixos;

vector<int> freqprefixos(1<<19, 0);
vector<int> freqsufixos(1<<19, 0);

int n, x, y, a, b, c, ant;

int main(){
	sc("%d %d %d\n", &n, &x, &y);
    sc("%d", &ant);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        prefixos.pb(a-ant);
        sufixos.pb(a-ant);
        ant = a;
    }
    for(int i = 0; i < n; i++) {
        if (i > 0) prefixos[i] += prefixos[i-1];
        freqprefixos[prefixos[i]]++;
    }
    for(int i = n-1; i >= 0; i--) {
        if (i < n-1) sufixos[i] += sufixos[i+1];
        freqsufixos[sufixos[i]]++;
    }

    fft(freqprefixos, false);
    fft(freqsufixos, false);
    for(int i = 0; i < (1<<19); i++) {
        freqprefixos[i] = (freqprefixos[i]*1LL*freqsufixos[i])%mod;
    }
    fft(freqprefixos, true);
    //for(int i = 1; i <= x; i++) {
    //    trace(i, ":", freqprefixos[i+x]);
    //}
    sc("%d", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        a /= 2;
        int maxi = -1;
        for(int j = 1; j*j <= a; j++) {
            if (a % j == 0) {
                b = j - y, c = (a / j) - y;
                if (b > 0 && b <= x && freqprefixos[b+x]) {
                    //trace("b:",b);
                    maxi = max(maxi, 2*(b+y));
                }
                if (c > 0 && c <= x && freqprefixos[c+x]) {
                    //trace("c:",c, j, a);
                    maxi = max(maxi, 2*(c+y));
                }
            }
        }
        if (i) pr(" ");
        pr("%d", maxi);
    }pr("\n");
 	return 0;
}
