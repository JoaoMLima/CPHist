#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

//Trace dinamico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

//DP debug
int recNum = 0;
void prTabs() { range(recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}
ll n, m, a, b, c;
ll dpt[11][2];
ll expo(ll a, ll b) {
	if (b == 0) return 1LL;
	if (b & 1LL) return a * expo(a, b-1);
	ll f = expo(a, b>>1);
	return f*f;
}
ll dp(int a, int b) {
	//trace(a, b);
	if(a == -1) return 1;
	ll res;
	if(dpt[a][b] == -1) {
		int digit = n % expo(10, a+1) / expo(10, a);
		if (b == 0) {
			res = LLONG_MIN;
			res = max(res, digit*dp(a-1, 0));
			for(int i = 0; i < digit; i++) {
				res = max(res, i*dp(a-1, 1));
			}
			dpt[a][b] = res;
		} else {
			res = LLONG_MIN;
			for(int i = 0; i <= 9; i++) {
				res = max(res, i*dp(a-1, 1));
			}
			dpt[a][b] = res;
		}
	}
	return dpt[a][b];
}

int main(){
	ll res = LLONG_MIN;
	memset(dpt, -1, sizeof dpt);
	sc("%lld\n", &n);
	int comecou = 0;
	for(int i = 10; i >= 0; i--) {
		if (!comecou) {
			if (n / expo(10, i)) {
				res = max(res, dp(i, 0));
				//trace(dp(i, 0));
				comecou = 1;
			}
		} else {
			res = max(res, dp(i, 1));
			//trace(dp(i, 1));
		}
	}
	pr("%lld\n", res);
 	return 0;
}
