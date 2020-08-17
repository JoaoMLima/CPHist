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


int n;

ll li[25][25];
ll mini[25][25];
ll maxi[25][25];

int t, a, b, q;
ll v;
int main(){
	cin >> n;
	for(int i = n-1; i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			if (i == n-1 || j == 0) {
				li[i][j] = 0;
			} else if (j == n-1) {
				li[i][j] = li[i+1][j-1]+1;
			} else {
				ll mi = mini[i+1][j];
				ll ma = maxi[i+1][j-1];
				li[i][j] = ma+1-mi;
			}
			if (i == n-1) {
				mini[i][j] = 0;
			} else {
				mini[i][j] = li[i][j] + mini[i+1][j];
			}
			if (j == n-1) {
				if (i == n-1) maxi[i][j] = 0;
				else {
					maxi[i][j] = li[i][j]+maxi[i+1][j];
				}
			} else {
				maxi[i][j] = li[i][j]+maxi[i][j+1];
			}
		}
	}
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (j) cout << " ";
			cout << li[i][j];
		}cout << endl;
	}
	cin >> q;
	while(q--) {
		cin >> v;
		int i = 0, j = 0;
		cout << "1 1" << endl;
		while(i != n-1 || j != n-1) {
			v -= li[i][j];
			if (i == n-1) j++;
			else if (j == n-1) i++;
			else {
				if (v > maxi[i+1][j]) {
					j++;
				} else {
					i++;
				}
			}
			cout << i+1 << " " <<  j+1 << endl;
		}
		
	}
	/*
	for(int i = 0; i < 25; i++) {
		for(int j = 0; j < 25; j++) {
			pr("%lld ", li[i][j]);
		}pr("\n");
	}*/
 	return 0;
}
