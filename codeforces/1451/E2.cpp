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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef EBUG
#include "trace.h"
#else
template<typename... Args>
void trace(Args... args) {}
template<typename... Args>
void recInit(Args... args) {}
template<typename... Args>
void recEnd(Args... args) {}
#endif

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
int xors[MAX];
int pos[MAX];

int t, n, k, b, c;
int main(){
	cin >> n;
	int pos1 = -1;
	int pos2 = -1;
	int repetido = 0;
	int zero = 0;
	for(int i = 2; i <= n; i++) {
		cout << "XOR " << 1 << " " << i << endl;
		cin >> xors[i];
		if (pos[xors[i]] != 0) {
			repetido = i;
		} else {
			pos[xors[i]] = i;
		}
		if (xors[i] == 0) {
			zero = i;
		}
		
		if (xors[i] == 1) pos1 = i;
		if (xors[i] == 2) pos2 = i;
	}
	int and1, and2;
	int inic;
	if (repetido) {
		cout << "AND " << repetido << " " << pos[xors[repetido]] << endl;
		cin >> and1;
		inic = and1^xors[repetido];
	} else if (zero) {
		cout << "AND " << 1 << " " << zero << endl;
		cin >> and1;
		inic = and1;
	} else {
		cout << "AND " << 1 << " " << pos1 << endl;
		cin >> and1;
		cout << "AND " << 1 << " "<< pos2 << endl;
		cin >> and2;
		inic = and1|and2;
	}
	
	cout << "! " << inic;
	for(int i = 2; i <= n; i++) {
		cout << " " << (inic^xors[i]);
	}cout << endl;


 	return 0;
}
