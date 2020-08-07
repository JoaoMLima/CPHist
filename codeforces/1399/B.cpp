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

int li[MAX];
int li2[MAX];

int n, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		int mini = 1000000007, mini2 = 1000000007;
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
			mini = min(mini, li[i]);
		}
		for(int i = 0; i < n; i++) {
			sc("%d", li2+i);
			mini2 = min(mini2, li2[i]);
		}
		ll r = 0;
		for(int i = 0; i < n; i++) {
			int x = min(li[i]-mini, li2[i]-mini2);
			r += x;
			r += li[i]-mini-x;
			r += li2[i]-mini2-x;
		}
		pr("%lld\n", r);
	}
 	return 0;
}
