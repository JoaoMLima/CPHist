#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 1000007
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

int required[MAX];

int n, t, a, b, c;
int main(){
	sc("%d", &n);
	vector<int> v(9, 0);
	int mini = 100001;
	for(int i = 0; i < 9; i++) {
		sc("%d", &v[i]);
		if (v[i] < mini) mini = v[i];
	}
	//cout << mini << endl;
	int qtdnum = n/mini;
	if (qtdnum == 0) {pr("-1\n");return 0;}
	//cout << qtdnum << endl;
	
	for(int i = 1; i <= qtdnum; i++) {
		required[i] = mini*i;
	}
	for(int i = qtdnum-1; i >= 0; i--) {
		for(int j = 9; j >= 1; j--) {
			if (n - v[j-1] >= required[i]) {n -= v[j-1];pr("%d", j);break;}
		}
	}pr("\n");

 	return 0;
}
