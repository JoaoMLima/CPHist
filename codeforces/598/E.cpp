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
int n, m, t, k;
int dpt[31][31][51];
int dp(int a, int b, int c) {
	if (c == 0) return 0;
	if (a * b < c) return 30000;
	if (a*b == c) return 0;
	if (dpt[a][b][c] == -1) {
		dpt[a][b][c] = 30000;
		for(int i = 1; i+i <= a; i++) {
			for(int j = 0; j <= c; j++) {
				dpt[a][b][c] = min(dpt[a][b][c], dp(i, b, j) + dp(a-i, b, c-j) + b*b);
			}
		}
		for(int i = 1; i+i <= b; i++) {
			for(int j = 0; j <= c; j++) {
				dpt[a][b][c] = min(dpt[a][b][c], dp(a, i, j) + dp(a, b-i, c-j) + a*a);
			}
		}
	}
	return dpt[a][b][c];
}

int main(){
	memset(dpt, -1, sizeof dpt);
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d %d", &n, &m, &k);
		pr("%d\n", dp(n, m, k));
	}
 	return 0;
}
