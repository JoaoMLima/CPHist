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
vector<int> primes;
vector<int> nums[1<<10];

int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		for(int i = 0; i < (1<<10); i++) {
			nums[i].clear();
		}
		primes.clear();
		sc("%d", &n);
		int c = n;
		for(int i = 2; i <= 31622; i++) {
			if (c % i == 0) primes.pb(i);
			while (c % i == 0) {
				c /= i;
			}
		}
		if (c != 1) {
			primes.pb(c);
		}
		for(ll i = 2; i*i <= n; i++) {
			if (n % i == 0) {
				int h = 0;
				for(int j = 0; j < sz(primes); j++) {
					if (i % primes[j] == 0) {
						h ^= (1<<j);
					}
				}nums[h].pb(i);
				if (i*i != n) {
					int x = n/i;
					h = 0;
					for(int j = 0; j < sz(primes); j++) {
						if (x % primes[j] == 0) {
							h ^= (1<<j);
						}
					}
					nums[h].pb(x);
				}
			}
		}
		nums[(1<<(sz(primes)))-1].pb(n);
		if (sz(primes) == 1) {
			for(int i : nums[1]) {
				pr("%d ", i);
			}
			pr("\n");
			pr("0\n");
			continue;
		}
		if (sz(primes) == 2) {
			for(int i : nums[1]) {
				pr("%d ", i);
			}
			if (sz(nums[3]) > 1) {
				for(int i = 1; i < sz(nums[3]); i++) {
					pr("%d ", nums[3][i]);
				}
			}
			for(int i : nums[2]) {
				pr("%d ", i);
			}
			pr("%d ", nums[3][0]);
			pr("\n");
			if (sz(nums[3]) > 1) pr("0\n");
			else pr("1\n");
			continue;
		}
		for(int i : nums[1]) {
			pr("%d ", i);
		}
		for(int i : nums[3]) {
			pr("%d ", i);
		}
		
		for(int i = 1; i < sz(primes); i++) {
			for(int j = 1<<i; j < (1<<(i+1)); j++) {
				if (j == (1<<i) + (1<<(i-1))) continue;
				for(int x : nums[j]) {
					pr("%d ", x);
				}
			}
			if (i < sz(primes)-1) {
				for(int x : nums[(1<<i) + (1<<(i+1))]) {
					pr("%d ", x);
				}
			}
		}pr("\n");
		pr("0\n");
	}

 	return 0;
}
