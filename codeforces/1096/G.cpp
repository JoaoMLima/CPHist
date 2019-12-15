#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int mod = 998244353;
const int root = 15311432;
const int root_1 = 469870224;
const int root_pw = 1<<23;

ll modpow(ll a, ll b) {
	if(b == 0LL) return 1LL;
	if(b & 1LL) return a*modpow(a, b-1)%998244353LL;
	ll x = modpow(a, b>>1);
	return x*x%998244353LL;
}
int inverse(int a) {
	return modpow(a, mod-2);
}


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
        int n_1 = inverse(n);
        for (int & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<int> multiply(vector<int> a,vector<int> b) {
	int l = a.size() + b.size();
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++)
        a[i] = (a[i]*1LL*b[i])%998244353LL;
    fft(a, true);
	a.resize(l);
    return a;
}

vector<int> expofft(vector<int> a,int b) {
    if(b == 0LL) return vector<int>(1, 1);
	if(b & 1LL) return multiply(a, expofft(a, b-1));
	vector<int> res = expofft(a, b>>1);

	return multiply(res, res);
}

int main(){
	int n, k, a;
	vector<int> v(10, 0);
	sc("%d %d", &n, &k);
	for(int i = 0; i < k; i++) {
		sc("%d", &a);
		v[a]++;
	}

	vector<int> res = expofft(v, n/2);
	/*
	for(int i = 0; i < (int)res.size(); i++) {
		pr("%d ", res[i]);
	}pr("\n");*/
	int r = 0;
	for(int i = 0; i < (int)res.size(); i++) {
		int tmp = (res[i]*1LL*res[i])%998244353LL;
		r = (r + tmp) % 998244353;
	}
	pr("%d\n", r);
 	return 0;
}