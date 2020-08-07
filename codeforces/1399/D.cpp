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

int resp[MAX];
int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		int mini = 1000000007, mini2 = 1000000007;
		int subseq = 0;
		set<int> seq0;
		set<int> seq1;
		for(int i = 0; i < n; i++) {
			if (getchar() == '0') {
				if (!seq1.empty()) {
					int x = *seq1.begin();
					seq1.erase(x);
					seq0.insert(x);
					resp[i] = x;
				} else {
					seq0.insert(++subseq);
					resp[i] = subseq;
				}
			} else {
				if (!seq0.empty()) {
					int x = *seq0.begin();
					seq0.erase(x);
					seq1.insert(x);
					resp[i] = x;
				} else {
					seq1.insert(++subseq);
					resp[i] = subseq;
				}
			}
		}getchar();
		pr("%d\n", subseq);
		for(int i = 0; i < n; i++) {
			if (i) pr(" ");
			pr("%d", resp[i]);
		}pr("\n");
	}
 	return 0;
}
