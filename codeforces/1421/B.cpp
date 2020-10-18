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



int n, t, a, b, c, d;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if (i == 0 && j == 1) a = getchar()-'0';
				else if (i == 1 && j == 0) b = getchar()-'0';
				else if (i == n-1 && j == n-2) c = getchar()-'0';
				else if (i == n-2 && j == n-1) d = getchar()-'0';
				else getchar();
			}getchar();
		}
		//trace(a, b, c, d);
		if (a == b && a == c && a == d) {
			pr("2\n1 2\n2 1\n");
		} else if (a == b && a == c) {
			pr("1\n%d %d\n", n, n-1);
		} else if (a == b && a == d) {
			pr("1\n%d %d\n", n-1, n);
		} else if (a == b) {
			pr("0\n");
		} else if (a == c && a == d) {
			pr("1\n1 2\n");
		} else if (a == c) {
			pr("2\n1 2\n%d %d\n", n-1, n);
		} else if (a == d) {
			pr("2\n1 2\n%d %d\n", n, n-1);
		} else {
			pr("1\n2 1\n");
		}
	}
 	return 0;
}
