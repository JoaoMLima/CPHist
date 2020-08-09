#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
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

ll fact[1000007];
ll invfact[1000007];

ll comb(int a, int b) {
	return MDL(MDL(fact[a]*invfact[b])*invfact[a-b]);
}

int li[3][1000007];
int dif(int i, int a, int b, int c) {
	return abs(li[0][i]-a) + abs(li[1][i]-b) + abs(li[2][i]-c);
}
int m;

int dpt[1000007][2][2][2];
int dp(int pos, int a, int b, int c) {
	if (pos == m) return 0;
	if (dpt[pos][a][b][c] == -1) {
		dpt[pos][a][b][c] = 10000000;
		for (int i = 0; i <= 1; i++) {
			for(int j = 0; j <= 1; j++) {
				for(int k = 0; k <= 1; k++) {
					if (((a+b+i+j) & 1) && ((b+c+j+k) & 1)) {
						dpt[pos][a][b][c] = min(dpt[pos][a][b][c], dp(pos+1, i, j, k) + dif(pos, i, j, k));
					}
				}
			}
		}
	}
	return dpt[pos][a][b][c];
}

int n, t, a, b, c;
int main(){
	memset(dpt, -1, sizeof dpt);
	sc("%d %d\n", &n, &m);
	if (n >= 4) {
		pr("-1\n");
		return 0;
	}
	if (n == 1) {
		pr("0\n");
		return 0;
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			char ch = getchar();
			li[i][j] = ch - '0';
		}getchar();
	}
	int imparindpar = 0, parindpar = 0, imparindimpar = 0, parindimpar = 0;
	if (n == 2) {
		for(int i = 0; i < m; i++) {
			if (i % 2 == 0) {
				if ((li[0][i]+li[1][i]) % 2 == 0) {
					parindpar++;
				} else {
					imparindpar++;
				}
			} else {
				if ((li[0][i]+li[1][i]) % 2 == 0) {
					parindimpar++;
				} else {
					imparindimpar++;
				}
			}
		}
		pr("%d\n", min(parindpar + imparindimpar, parindimpar + imparindpar));
		return 0;
	}
	int r = dp(1, 0, 0, 0) + dif(0, 0, 0, 0);
	r = min(r, dp(1, 0, 0, 1) + dif(0, 0, 0, 1));
	r = min(r, dp(1, 0, 1, 0) + dif(0, 0, 1, 0));
	r = min(r, dp(1, 0, 1, 1) + dif(0, 0, 1, 1));
	r = min(r, dp(1, 1, 0, 0) + dif(0, 1, 0, 0));
	r = min(r, dp(1, 1, 0, 1) + dif(0, 1, 0, 1));
	r = min(r, dp(1, 1, 1, 0) + dif(0, 1, 1, 0));
	r = min(r, dp(1, 1, 1, 1) + dif(0, 1, 1, 1));
	pr("%d\n", r);
 	return 0;
}
