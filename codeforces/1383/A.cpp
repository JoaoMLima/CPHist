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

int A[MAX];
int B[MAX];
int reach[22][22];
set<int> g[22];

int n, t;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		for(int i = 20; i >= 0; i--) {
			g[i].clear();
			for(int j = 20; j >= 0; j--) {
				reach[i][j] = 0;
			}
		}
		vector<int> qtd(20, 0);
		for(int i = 0; i < n; i++) {
			A[i] = getchar()-'a';
			qtd[A[i]]++;
		}getchar();
		for(int i = 0; i < n; i++) {
			B[i] = getchar()-'a';
			qtd[B[i]]++;
		}getchar();

		int ok = 1;
		for(int i = 0; i < n; i++) {
			if (A[i] < B[i]) {
				g[A[i]].insert(B[i]);
			}
			
			if (A[i] > B[i]) {
				ok = 0;break;
			}
		}
		if (!ok) {
			pr("-1\n");
			continue;
		}
		int r = 0;
		for(int i = 19; i >= 0; i--) {
			reach[i][i] = 1;
			for(int c : g[i]) {
				if (!reach[i][c]) {
					//pr("%c %c\n", (char)(i+'a'), (char)(c+'a'));
					r++;
				}
				int tmp = c;
				for(int j = c-1; j >= i; j--) {
					if (reach[j][c]) tmp = j;
				}
				for(int j = 19; j >= 0; j--) {
					if (reach[tmp][j]) {
						//pr("soma: %d %d\n", i, j);
						reach[i][j] = 1;
					}
				}
			}
		}
		pr("%d\n", r);
	}
 	return 0;
}
