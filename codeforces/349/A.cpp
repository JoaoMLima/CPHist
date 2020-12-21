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



int n, t, a, b, c;
int main(){
	sc("%d", &n);
	int qtd50 = 0;
	int qtd25 = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a == 25) {
			qtd25++;
		} else if (a == 50 && qtd25 >= 1) {
			qtd25--;
			qtd50++;
		} else if (a == 100 && qtd50 >= 1 && qtd25 >= 1) {
			qtd50--;
			qtd25--;
		} else if (a == 100 && qtd25 >= 3) {
			qtd25 -= 3;
		} else {
			pr("NO\n");
			return 0;
		}
	}
	pr("YES\n");
 	return 0;
}
