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
#define EPS 1e-12
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



int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		int n, k;
		cin >> n >> k;
		cin >> s;
		int qtd = 0;
		int qtdi = 0;
		int ok = 1;
		for(int i = 0; i < k; i++) {
			char c = '?';
			for(int j = i; j < n; j+= k) {
				if (s[j] == '1') c = '1';
				if (s[j] == '0') c = '0';
			}
			if (c == '1') {
				for(int j = i; j < n; j+= k) {
					if (s[j] == '0') ok = 0;
					s[j] = '1';
				}
			} else if (c == '0') {
				for(int j = i; j < n; j+= k) {
					if (s[j] == '1') ok = 0;
					s[j] = '0';
				}
			}
		}
		for(int i = 0; i < k; i++) {
			if (s[i] == '1') qtd++;
			if (s[i] == '?') qtdi++;
		}
		if (!ok || qtd > k/2 || qtd + qtdi < k/2) pr("NO\n");
		else pr("YES\n");
	}
 	return 0;
}
