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

using cd = complex<double>;
const double PI = acos(-1);

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
        double ang = 2 * PI / len * (invert ? -1 : 1);
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

vector<int> multiply(vector<int> const& a, vector<int> const& b, int lmax) {
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

    vector<int> result(lmax);
    for (int i = 0; i < lmax; i++)
        result[i] = round(fa[i].real());
    return result;
}

vector<int> s[4];
vector<int> t[4];
vector<int> ok;
int qtd[4];
int get(char ch) {
	if(ch == 'A') return 0;
	if(ch == 'T') return 1;
	if(ch == 'G') return 2;
	return 3;
}

int main(){
	int n, m, k;
	sc("%d %d %d\n", &n, &m, &k);
	ok.resize(n, 1);
	for(int i = 0; i < 4; i++) {
		s[i].resize(n, 0);
		t[i].resize(n, 0);
	}

	for(int i = 0; i < n; i++) {
		int lt = get(getchar());
		s[lt][n-1-i] = 1;
	}getchar();

	for(int i = 0; i < m; i++) {
		int lt = get(getchar());
		t[lt][i] = 1;
		qtd[lt]++;
	}getchar();

	for(int i = 0; i < 4; i++) {
		int last = -300000;
		for(int j = 0; j < n; j++) {
			if(s[i][j] == 1) last = j;
			if(j-last <= k) s[i][j] = 1;
		}
		last = 500000;
		for(int j = n-1; j >= 0; j--) {
			if(s[i][j] == 1) last = j;
			if(last-j <= k) s[i][j] = 1;
		}
	}
	/*
	for(int i = 0; i < 4; i++) {
		pr("%d: ",qtd[i]);
		for(int j = 0; j < n; j++) {
			pr("%d ", s[i][j]);
		}pr("\n");
		for(int j = 0; j < n; j++) {
			pr("%d ", t[i][j]);
		}pr("\n");
		pr("\n");
	}pr("\n");
*/
	int r = 0;
	
	for(int i = 0; i < 4; i++) {
		vector<int> res = multiply(s[i], t[i], n);
		/*
		for(int j = 0; j < n; j++) {
			pr("%d ", res[j]);
		}pr("\n");
		*/
		for(int j = m-1; j < n; j++) {
			if(res[j] != qtd[i]) {
				ok[j] = 0;
			}
		}
	}
	
	for(int j = m-1; j < n; j++) {
		if(ok[j]) r++;
	}
	pr("%d\n", r);
 	return 0;
}