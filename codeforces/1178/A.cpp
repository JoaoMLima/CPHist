#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
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
int n, m, a, b, c;

int main(){
	sc("%d", &n);
	sc("%d", &m);
	int total = m;
	int totalPartido = m;
	vi resp;
	resp.pb(1);
	for(int i = 1; i < n; i++ ){
		sc("%d", &a);
		total += a;
		if (a*2 <= m) {
			resp.pb(i+1);
			totalPartido += a;
		}
	}
	if (totalPartido * 2 > total) {
		pr("%d\n", (int)resp.size());
		for(int x : resp) {
			pr("%d ", x);
		}
		pr("\n");
	} else {
		pr("0\n");
	}
 	return 0;
}
