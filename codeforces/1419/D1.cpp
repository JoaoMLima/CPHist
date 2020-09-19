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
int li[MAX];
int fin[MAX];
set<ii> s;
int resp = 0;

int n, t, a, b, c;
int main(){
	sc("%d\n", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
		s.insert({li[i], i});
	}
	if (n <= 2) {
		for(int i = 0; i < n; i++) {
			fin[i] = li[i];
		}
	} else {
		ii inic = *prev(s.end());s.erase(inic);
		fin[0] = inic.fi;
		for(int i = 1; i <= (n-1)/2; i++) {
			ii x = *prev(s.end());s.erase(x);
			fin[i*2] = x.fi;
		}
		for(int i = (n-1)/2; i >= 1; i--) {
			set<ii>::iterator it = s.lower_bound({fin[i*2], -1});
			if (it == s.begin()) {
				ii x = *prev(s.end());s.erase(x);
				fin[(i*2)-1] = x.fi;
			} else {
				ii x = *prev(it);s.erase(x);
				fin[(i*2)-1] = x.fi;
				resp++;
			}
		}
		if (n%2 == 0) {
			fin[n-1] = s.begin()->fi;
		}
	}
	pr("%d\n", resp);
	for(int i = 0; i < n; i++) {
		if (i) pr(" ");
		pr("%d", fin[i]);
	}pr("\n");

 	return 0;
}
