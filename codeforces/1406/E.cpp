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

vector<ll> neg;
vector<ll> pos;
int n, t; ll a, b, c;
vector<int> primes1;
vector<int> primes2;
int sieve[MAX];
int main(){
	cin >> n;
	for(int i = 2; i <= n; i++) {
		sieve[i] = 1;
	}
	for(int i = 2; i <= n; i++) {
		if (sieve[i]) {
			if (i < 317) {
				primes1.pb(i);
				for(int j = i*i; j <= n; j += i) {
					sieve[j] = 0;
				}
			} else {
				primes2.pb(i);
			}
		}
	}
	ll resp = 1;
	for(int i = 0; i < sz(primes1); i++) {
		cout << "B " << primes1[i] << endl;
		cin >> a;
	}
	for(int i = 0; i < sz(primes1); i++) {
		ll x = primes1[i];
		cout << "B " << x << endl;
		cin >> a;
		while(a >= 1) {
			resp *= primes1[i];
			x *= primes1[i];
			if (x > n) break;
			cout << "B " << x << endl;
			cin >> a;
		}
	}
	//trace(resp);
	int l = 0, r = sz(primes2)-1;
	cout << "A 1" << endl;
	cin >> a;
	int qtdant = a;
	while(l <= r) {
		int m = (l+r)/2;
		int qtd = m-l+1;
		for(int i = l; i <= m; i++) {
			cout << "B " << primes2[i] << endl;
			cin >> a;
			if (a > 1) {
				resp *= primes2[i];
				cout << "C " << resp << endl;
				return 0;
			}
		}
		cout << "A 1" << endl;
		cin >> a;
		if (a == qtdant-qtd) {
			l = m+1;
			qtdant = a;
		} else {
			for(int i = l; i <= m; i++) {
				cout << "B " << primes2[i] << endl;
				cin >> a;
				if (a) {
					resp *= primes2[i];
					cout << "C " << resp << endl;
					return 0;
				}
			}
		}
	}

	cout << "C " << resp << endl;
	
	return 0;
}
