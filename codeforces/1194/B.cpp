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
int n, m, a, b, c, t;


int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d\n", &n, &m);
		//trace(n, m, t);
		vector<vi> li(n, vi(m, 0));
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (i) li[i][j] += li[i-1][j];
				if (j) li[i][j] += li[i][j-1];
				if (i && j) li[i][j] -= li[i-1][j-1];
				char ch = getchar();
				//trace("char ", ch);
				if (ch == '*') li[i][j]++;
			}getchar();
		}
		
		int mini = n+m-1;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				int preco = 0;
				preco += li[n-1][j];
				if (j) preco -= li[n-1][j-1];
				preco += li[i][m-1];
				if (i) preco -= li[i-1][m-1];
				int cell = 0;
				cell += li[i][j];
				if (i) cell -= li[i-1][j];
				if (j) cell -= li[i][j-1];
				if (i && j) cell += li[i-1][j-1];
				if (cell) preco--;
				mini = min(mini, n+m-1-preco);
			}
		}
		pr("%d\n", mini);
	}
 	return 0;
}
