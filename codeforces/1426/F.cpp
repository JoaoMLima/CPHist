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
typedef pair<ll, ll> ii;

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

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}


ll qtd[4][4];
int n;
string s;
int main(){
	cin >> n;
	cin >> s;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if (s[i] == 'a') qtd[1][0]++;
		else if (s[i] == 'b') {
			qtd[2][0] = (qtd[2][0] + qtd[1][0]) % MOD;
			qtd[2][1] = (qtd[2][1] + qtd[1][1]) % MOD;
		} else if (s[i] == 'c') {
			qtd[3][0] = (qtd[3][0] + qtd[2][0]) % MOD;
			qtd[3][1] = (qtd[3][1] + qtd[2][1]) % MOD;
			qtd[3][2] = (qtd[3][2] + qtd[2][2]) % MOD;
		} else {
			qtd[3][1] = (qtd[3][1] + qtd[2][0]) % MOD;
			qtd[3][2] = (qtd[3][2] + qtd[2][1]) % MOD;
			qtd[3][3] = (qtd[3][3] + qtd[2][2]) % MOD;

			qtd[2][1] = (qtd[2][1] + qtd[1][0]) % MOD;
			qtd[2][2] = (qtd[2][2] + qtd[1][1]) % MOD;

			qtd[1][1]++;
			cnt++;
		}
	}
	ll resp = 0LL;
	for(int i = 0; i <= min(3, cnt); i++) {
		resp = (resp + qtd[3][i]*modpow(3, cnt-i, MOD)) % MOD;
	}
	
	pr("%lld\n", resp);
 	return 0;
}
