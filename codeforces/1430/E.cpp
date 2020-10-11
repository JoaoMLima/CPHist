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

map<int, int> m;

ll bit[2*MAX];

ll query(int i) {
	i = 200003-i;
	ll s = 0LL;
	while(i) {
		s += bit[i];
		i -= i&(-i);
	}
	return s;
}

void update(int i) {
	i = 200003-i;
	while(i < 2*MAX) {
		bit[i]++;
		i += i&(-i);
	}
}


int n, t, a, b, c, k;
string s;
int li[2*MAX];
vector<queue<int> > pos(26);
int main(){
	sc("%d\n", &n);
	cin >> s;
	for(int i = 1; i <= n; i++) {
		int p = n-i;
		pos[s[p]-'a'].push(i);
	}
	for(int i = 1; i <= n; i++) {
		int p = i-1;
		li[i] = pos[s[p]-'a'].front();
		pos[s[p]-'a'].pop();
	}
	ll resp = 0LL;
	for(int i = 1; i <= n; i++) {
		resp += query(li[i]);
		update(li[i]);
	}
	pr("%lld\n", resp);
 	return 0;
}
