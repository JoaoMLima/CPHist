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

vector<int> g[MAX];

int subtree[MAX];

int n, t, a, b, c;

void dfs(int v, int p) {
	subtree[v] = 1;
	for(int ch : g[v]) {
		if (ch == p) continue;
		dfs(ch, v);
		subtree[v] += subtree[ch];
	}
}

int busca(int v, int p) {
	int maior = 0;
	int id = 0;	
	for(int ch : g[v]) {
		if (ch == p) continue;
		if (subtree[ch] > maior) {
			maior = subtree[ch];
			id = ch;
		}
	}
	if (maior > n/2) {
		return busca(id, v);
	} else {
		return v;
	}
}



void busca2(int v) {
	int maior = 0;
	int id = 0;	
	for(int ch : g[v]) {
		//trace("a",ch, subtree[ch]);
		if (subtree[ch] > maior) {
			maior = subtree[ch];
			id = ch;
		}
	}
	//trace(id);
	if (maior >= n/2 + n%2) {
		for(int ch : g[id]) {
			if (ch == v) continue;
			pr("%d %d\n", id, ch);
			pr("%d %d\n", v, ch);
			break;
		}
	} else {
		pr("%d %d\n", v, id);
		pr("%d %d\n", v, id);
	}
}



int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 1; i <= n; i++) {
			g[i].clear();
		}
		for(int i = 0; i < n-1; i++) {
			sc("%d %d", &a, &b);
			g[a].pb(b);
			g[b].pb(a);
		}
		dfs(1, -1);
		c = busca(1, -1);
		//trace("c", c);
		dfs(c, -1);
		//trace("c", c);
		busca2(c);
	}
 	return 0;
}
