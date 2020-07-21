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

deque<char> a;

vector<char> b;
vector<int> resps;
int n, t;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		int inverts = 0;
		resps.clear();
		a.clear();
		b.clear();
		for(int i = 0; i < n; i++) {
			a.push_back(getchar());
		}getchar();
		for(int i = 0; i < n; i++) {
			b.push_back(getchar());
		}getchar();
		for(int i = n-1; i > 0; i--) {
			if (inverts % 2 == 0) {
				char c = a.front();
				//pr("%c ", c);
				if (c == b[i]) {
					resps.pb(1);
				}
				a.pop_front();
				inverts++;
				resps.pb(i+1);
			} else {
				char c = a.back();
				if (c == '1') c = '0';
				else c = '1';
				//pr("%c ", c);
				if (c == b[i]) {
					resps.pb(1);
				}
				a.pop_back();
				inverts++;
				resps.pb(i+1);
			}
		}//pr("\n");
		char c = a.front();
		if (inverts % 2 == 1) {
			if (c == '1') c = '0';
			else c = '1';
		} 
		if (c != b[0]) {
			inverts++;
			resps.pb(1);
		}
		pr("%d", sz(resps));
		for(int i = 0; i < sz(resps); i++) {
			pr(" %d", resps[i]);
		}pr("\n");
	}
 	return 0;
}
