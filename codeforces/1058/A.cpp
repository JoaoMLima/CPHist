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
typedef pair<int, ll> il;
typedef pair<ll, int> li;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, vector<int> > piv;
il parent[17][100001];
int height[100001];
int ranks[100001];
vector<ii> g[100001];
vector<ii> g2[100001];
int recurNumber = 0;
ll dists[42][100001];
void recInit(int x, int y, int z) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "Rec(" << x << ", " << y << ", " << z << "):\n";
	recurNumber++;}
void recEnd(int x) {
	for(int i = 0; i < recurNumber; i++){ cout << "    ";}
	cout << "-> " << x << "\n";
	recurNumber--;}

int n, m, q, k, t, a, b, c, x, y, z, w;
int main() {
	sc("%d\n", &n);
	char r = '0';
	for(int i = 0; i < n; i++) {r |= getchar(); getchar();}
	if (r == '1') {
		pr("HARD\n");
	} else  {
		pr("EASY\n");
	}
}