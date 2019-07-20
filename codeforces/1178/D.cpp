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
char ch;
char last = 's';
int primo[2010];
int main(){
	for(int i = 2; i < 2010; i++) {
		int valido = 1;
		for(int j = 2; j < i; j++) {
			if (i % j == 0) {valido = 0; break;}

		}
		if (valido) {primo[i] = 1;}
	}
	sc("%d\n", &n);
	if (n == 3) {
		pr("3\n");
		pr("1 2\n");
		pr("2 3\n");
		pr("3 1\n");
		return 0;
	}
	vector<ii> resp;
	for(int i = 1; i <= n; i++) {
		if (i != n) {
			resp.pb({i, i+1});
		}
		else {
			resp.pb({n, 1});
		}
	}
	int edges = n;
	int i = 1, j = 1+(n/2);
	while(!primo[edges]) {
		edges++;
		resp.pb({i, j});
		i++; j++;
	}
	pr("%d\n", (int)resp.size());
	for(ii par : resp) {
		pr("%d %d\n", par.fi, par.se);
	}
 	return 0;
}
