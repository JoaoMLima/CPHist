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



int t, n, a, b, c;
char w[MAX];
char s[MAX];
int main(){
	sc("%d\n", &t);
	while(t--) {
		char ch = getchar();
		n = 0;
		while(ch != '\n') {
			w[n++] = ch;
			ch = getchar();
		}
		sc("%d\n", &a);
		for(int i = 0; i < n; i++) {
			s[i] = '1';
		}
		for(int i = 0; i < n; i++) {
			if (w[i] == '0') {
				if (i-a >= 0) s[i-a] = '0';
				if (i+a < n) s[i+a] = '0';
			}
		}
		int ok = 1;
		for(int i = 0; i < n; i++) {
			ch = '0';
			if (i-a >= 0 && s[i-a] == '1') {
				ch = '1';
			}
			if (i+a < n && s[i+a] == '1') {
				ch = '1';
			}
			if (ch != w[i]) ok = 0;
		}
		if (ok) {
			for(int i = 0; i < n; i++) putchar(s[i]);putchar('\n');
		} else {
			pr("-1\n");
		}
	}
 	return 0;
}
