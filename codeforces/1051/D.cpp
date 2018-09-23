#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 998244353
#define md(x) (x) % mod
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, vector<int> > piv;
int n, q, k, t, x, y, z, w, recurNumber = 0;

void recInit(int a, int b, int c) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "Rec(" << a << ", " << b << ", " << c << "):\n";
	recurNumber++;
}
void recEnd(int a) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "-> " << a << "\n";
	recurNumber--;
}

int dpt[1000][2000][4];
int dp(int a, int b, int c) {
	//recInit(a, b, c);
	if (a == 0) {
		if (b == 0) {
			//recEnd(1);
			return 1;
		} else {
			//recEnd(0);
			return 0;
		}
	}
	if (dpt[a][b][c] == -1) {
		if (c == 0) {
			dpt[a][b][c] = md(md(dp(a-1, b, 0) + dp(a-1, b-1, 1)) + md(dp(a-1, b-1, 2) + dp(a-1, b-1, 3)));
		} else if (c == 1) {
			dpt[a][b][c] = md(md(dp(a-1, b, 0) + dp(a-1, b, 1)) + md(dp(a-1, b-2, 2) + dp(a-1, b, 3)));
		} else if (c == 2) {
			dpt[a][b][c] = md(md(dp(a-1, b, 0) + dp(a-1, b-2, 1)) + md(dp(a-1, b, 2) + dp(a-1, b, 3)));
		} else {
			dpt[a][b][c] = md(md(dp(a-1, b-1, 0) + dp(a-1, b-1, 1)) + md(dp(a-1, b-1, 2) + dp(a-1, b, 3)));
		}
	}
	//recEnd(dpt[a][b][c]);
	return dpt[a][b][c];
}
int main() {
	for(int i = 0; i < 1000; i++) {
		for(int j = 0; j < 2000; j++) {
			for(int k = 0; k < 4; k++) {
				dpt[i][j][k] = -1;
			}
		}
	}
	sc("%d %d\n", &n, &k);
	//memset(dpt, -1, sizeof(dpt));
	pr("%d\n", md(md(dp(n-1, k-1, 0) + dp(n-1, k-2, 1)) + md(dp(n-1, k-2, 2) + dp(n-1, k-1, 3))));
}