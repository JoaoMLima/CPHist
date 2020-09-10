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
int vi[10007];
int res[10007];

int main(){
	cin >> n;
	int ant = 1;
	for(int i = 2; i <= n; i++) {
		cout << "? " << ant << " " << i << endl;
		cin >> a;
		cout << "? " << i << " " << ant << endl;
		cin >> b;
		if (a > b) {
			//pos i = 1
			vi[a] = 1;
			res[ant] = a;
			ant = i;
		} else {
			//pos i+1 = b
			vi[b] = 1;
			res[i] = b;
		}
	}
	for(int i = 1; i <= n; i++) {
		if (!vi[i]) {
			res[ant] = i;
		}
	}
	cout << "! ";
	for(int i = 1; i <= n; i++) {
		if (i > 1) cout << " ";
		cout << res[i];
	}cout << endl;
	
 	return 0;
}
