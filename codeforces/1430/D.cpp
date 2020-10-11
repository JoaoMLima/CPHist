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


int n, t, a, b, c, k;
vector<int> v;
queue<int> q;
int main(){
	sc("%d\n", &t);
	while(t--) {
		v.clear();
		while(!q.empty()) {
			q.pop();
		}
		sc("%d\n", &n);
		int ult = getchar()-'0';
		int qtd = 1;
		for(int i = 1; i < n; i++) {
			if (getchar()-'0' != ult) {
				v.pb(qtd);
				qtd = 1;
				ult = !ult;
			} else {
				qtd++;
			}
		}getchar();
		v.pb(qtd);
		for(int i = 0; i < sz(v);i++) {
			q.push(i);
		}
		int i = 0;
		int j = 0;
		while(i < sz(v)) {
			while(!q.empty() && (q.front() < i || v[q.front()] < 2)) {
				q.pop();
			}
			if (q.empty()) {
				i += 2;
			} else {
				v[q.front()]--;
				i++;
			}
			j++;
		}
		pr("%d\n", j);
	}
 	return 0;
}
