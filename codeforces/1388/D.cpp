#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
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

ll a[MAX];
set<ii> b[MAX]; //next // soma?
int qtd[MAX];
set<ii> lig;
vector<int> seqresp;

int n, t;
int main(){
	sc("%d", &n);
	for(int i = 1; i <= n; i++) {
		b[i].clear();
		sc("%lld", a+i);
		qtd[i] = 0;
		lig.insert({qtd[i], i});
	}
	for(int i = 1; i <= n; i++) {
		int tmp;
		sc("%d", &tmp);
		b[i].insert({tmp, 1});
		if (tmp != -1) {
			lig.erase({qtd[tmp], tmp});
			qtd[tmp]++;
			lig.insert({qtd[tmp], tmp});
		}
	}
	ll resp = 0;
	while(!lig.empty()) {
		ii f = *lig.begin(); lig.erase(f);
		//qtd no
		int v = f.se;
		vector<ii> remove;
		//pr("v: %d\n", v);
		int ok = 1;
		for(ii p : b[v]) {
			if (p.fi != -1 && p.se && a[v] < 0) {
				//pr("2 v: %d qtd: %d p: {%d , %d}\n", v, qtd[v], p.fi, p.se);
				lig.erase({qtd[p.fi], p.fi});
				qtd[p.fi]--;
				//if (p.fi == 8) pr("2 - %d\n", v);
				lig.insert({qtd[p.fi], p.fi});
				remove.pb(p);
				//pr("insere: %d -> %d\n", p.fi, v);
				b[p.fi].insert({v, 0});
				qtd[v]++;
				//if (v == 8) pr("+ %d\n", v);
				lig.insert({qtd[v], v});
				ok = 0;
			}
		}
		if (ok) {
			for(ii p : b[v]) {
				if (p.fi != -1 && (a[v] >= 0 || (!p.se))) {
						//pr("1: %d %d %d\n", a[v] >= 0, !p.se, p.se);
						//pr("1 v: %d %lld p: {%d , %d}\n", v, a[v], p.fi, p.se);
						if (p.se) a[p.fi] += a[v];
						lig.erase({qtd[p.fi], p.fi});
						qtd[p.fi]--;
						//if (p.fi == 8) pr("1 - %d\n", v);
						lig.insert({qtd[p.fi], p.fi});
						remove.pb(p);
				}
			}
		}
		for(ii p : remove) {
			//pr("remove: %d -> %d\n", v, p.fi);
			b[v].erase(p);
		}
		if (qtd[v] == 0) {
			resp += a[v];
			seqresp.pb(v);
			//pr("finaliza %d\n", v);
			//pr("resp: %lld\n", resp);
		}
	}
	pr("%lld\n", resp);
	int prt = 0;
	for(int x : seqresp) {
		if (prt) pr(" ");
		pr("%d", x);
		prt = 1;
	}pr("\n");
 	return 0;
}
