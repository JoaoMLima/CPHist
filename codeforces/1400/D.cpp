#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 3007
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
int freq[MAX];
ll dp1[MAX][MAX];
ll dp2[MAX][MAX];
ll dp3[MAX][MAX];
int li[MAX];
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
		}
		for(int i = 1; i <= n; i++) { //posicao
			freq[i] = 0;
			for(int j = 1; j <= n; j++) { //numero
				dp1[i][j] = 0;
				dp2[i][j] = 0;
				dp3[i][j] = 0;
			}
		}
		for(int i = 1; i <= n; i++) { //posicao
			for(int j = 1; j <= n; j++) { //numero
				dp3[li[i]][j] += dp2[j][li[i]];
				dp2[li[i]][j] += dp1[j][li[i]];
				dp1[li[i]][j] += freq[j];
				
				//trace("pos:", i, "num1:", li[i], "num2:", j);
				//trace(dp3[li[i]][j], dp2[li[i]][j], dp1[li[i]][j], freq[li[i]]);
			}
			freq[li[i]]++;
		}
		ll resp = 0LL;
		for(int i = 1; i <= n; i++) { //posicao
			for(int j = 1; j <= n; j++) { //numero
				resp += dp3[i][j];
			}
		}
	pr("%lld\n", resp);
	}
 	return 0;
}
