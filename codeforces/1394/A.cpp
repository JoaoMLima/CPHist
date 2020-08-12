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
vector<ll> menores;
vector<ll> maiores;
int accum[MAX];
int n, t, a, b, c, d, m;
int main(){
	sc("%d %d %d", &n, &d, &m);
	ll total = 0;
	ll totalmenores = 0;
	ll totalmaiores = 0;
	ll resp = 0;
	for(int i = 1; i <= n; i++) {
		sc("%d", li+i);
		if (li[i] <= m) {menores.pb(li[i]);totalmenores += li[i];}
		else maiores.pb(li[i]);
	}
	if (sz(maiores) == 0) {
		resp = totalmenores;
		pr("%lld\n", resp);
		return 0;
	}
	sort(menores.begin(), menores.end());
	sort(maiores.begin(), maiores.end(), greater<ll>());
	for(int i = 1; i < sz(menores); i++) {
		menores[i] += menores[i-1];
	}
	for(int i = 1; i < sz(maiores); i++) {
		maiores[i] += maiores[i-1];
	}
	//trace("menores", totalmenores);
	//trace("aqui");
	for(int i = 1; i <= sz(maiores); i++) {
		ll precisatirar = (i-1)*1LL*d;
		//trace("aqui2", i, precisatirar);
		if (precisatirar > sz(maiores) + sz(menores) - i) {
			continue;
		}
		//trace("aqui3", i, precisatirar);
		if (precisatirar < sz(maiores) - i) {
			if ((sz(maiores) - i) - precisatirar <= d) {
				precisatirar = sz(maiores) - i;
			} else {
				continue;
			}
		}
		//
		precisatirar -= sz(maiores) - i;
		//trace(i, precisatirar);
		if (precisatirar == 0) {//trace("aqui4", i, precisatirar, maiores[i-1] + totalmenores);
		resp = max(resp, maiores[i-1] + totalmenores);}
		else {//trace("aqui4", i, precisatirar, maiores[i-1] + totalmenores - menores[precisatirar-1]); 
		resp = max(resp, maiores[i-1] + totalmenores - menores[precisatirar-1]);}
	}

	
	pr("%lld\n", resp);
 	return 0;
}
