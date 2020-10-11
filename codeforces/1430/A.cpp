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



int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d", &n);
		if(n <= 2) pr("-1\n");
		else if (n == 3) pr("1 0 0\n");
		else if (n == 4) pr("-1\n");
		else if (n == 5) pr("0 1 0\n");
		else if (n == 6) pr("2 0 0\n");
		else if (n == 7) pr("0 0 1\n");
		else {
			if (n % 3 == 0) pr("%d 0 0\n", n / 3);
			else if (n % 3 == 1) pr("%d 0 1\n", (n-7) / 3);
			else pr("%d 1 0\n", (n-5) / 3);
		}
	}
 	return 0;
}
