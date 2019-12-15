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

using cd = complex<ld>;
const ld PI = acos(-1.0L);

void fft(vector<cd> & a, bool invert) {
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
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(vector<ll> & a,vector<ll> & b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


int li[200010];
vector<ll> pre;
vector<ll> suf;
int main(){
	int n, a, b, c;
	sc("%d %d", &n, &a);
	pre.resize(n+1);
	suf.resize(n+1);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	int accum = 0;
	ll sub = 0;
	vector<int> pos;
	pos.pb(0);
	for(int i = 0; i < n; i++) {
		if (li[i] < a) {
			if(i) pos.pb(i);
			accum++;
		}
		pre[accum]++;
	}
	if(pos[(int)pos.size()-1] != n-1) pos.pb(n-1);
	for(int i = 1; i < (int)pos.size(); i++) {
		//pr("%d ", pos[i]);
		sub += ((1+pos[i]-pos[i-1])*1LL*(pos[i]-pos[i-1]))/2LL;
	}//pr("\n");
	accum = 0;
	for(int i = n-1; i >= 0; i--) {
		if (li[i] < a) accum++;
		suf[accum]++;
	}
	int tot = accum;

	vector<ll> result = multiply(pre, suf);
	pr("%lld", result[tot]-sub);
	for(int i = tot+1; i <= tot+n; i++) {
		pr(" %lld", result[i]);
	}pr("\n");

 	return 0;
}