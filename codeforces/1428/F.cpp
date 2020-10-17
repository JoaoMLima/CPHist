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

ll dp[5*MAX];
ll li[5*MAX];

ll last[5*MAX];
ll query(ll i) {
	ll s = 0;
	i = 5*MAX-4 - i;
	while(i) {
		s = max(s, last[i]);
		i -= i&(-i);
	}
	return s;
	//if (s == -1) return 1;
	//return s-i+1;
}
void update(ll i, ll v) {
	i = 5*MAX-4 - i;
	while(i < 5*MAX) {
		last[i] = max(last[i], v);
		i += i&(-i);
	}
}

int n, t, a, b, c, d;
int main(){
	sc("%d\n", &n);
	for(int i = 1; i <= n; i++) {
		li[i] = (getchar() == '1');
	}
	ll seq = 0;
	for(int i = 1; i <= n; i++) {
		if (!li[i]) {
			dp[i] = dp[i-1];
			seq = 0;
		} else {
			seq++;
			dp[i] = ((1LL+seq)*seq)/2LL;
			ll l = query(seq+1);
			//trace("tr1", i, dp[i], l);
			if (l == 0) {
				dp[i] += (i-seq)*seq;
			} else {
				//trace("tr12", i-seq, l-seq);
				dp[i] += (i-seq-(l-seq+1)+1)*seq;
				//trace("tr2", i, dp[i]);
				dp[i] += dp[l];
				//trace("tr3", i, dp[i]);
				dp[i] -= ((1LL+seq)*seq)/2LL;
				//trace("tr4", i, dp[i]);
			}
			update(seq, i);
		}
	}
	ll resp = 0LL;
	for(int i = 1; i <= n; i++) {
		resp += dp[i];
		//pr("i: %d -> %lld\n", i, dp[i]);
	}
	pr("%lld\n", resp);


 	return 0;
}
