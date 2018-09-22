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
#define mod 1000000007
#define md(x) (x) % mod;
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
int n, q, k, t, a, b, c, x, y, z, w;
char s[100];
char ch;
int li[100];
map<int, pair<int, char > > m;
int main() {
	sc("%d\n", &n);
	for(int i = 0; i < n; i++) {
		sc("%d\n", &a);
		if (m.count(a)) {
			m[a].fi++;
		} else {
			m[a] = mp(1, 'A');
		}
		li[i] = a;
	}
	map<int, pair<int, char > >::iterator it = m.begin();
	a = 0; b = 0;
	for(it; it != m.end(); it++) {
		if ((*it).se.fi == 1) {
			a++;
		} else if ((*it).se.fi > 2) {
			b++;
		}
	}
	if((a & 1) && b == 0) {
		pr("NO\n");
		return 0;
	}
	pr("YES\n");
	int eq = 0;
	if(a & 1) {
		eq = 1;
	}
	int sa = 0, sb = 0;

	for(int i = 0; i < n; i++) {
		if (m[li[i]].fi == 1) {
			if (sa > sb) {
				putchar('B');
				sb++;
			} else {
				putchar('A');
				sa++;
			}
		} else if (m[li[i]].fi > 2 && eq) {
			if (sa > sb) {
				putchar('B');
				sb++;
				m[li[i]].se = 'A';
			} else {
				sa++;
				putchar('A');
				m[li[i]].se = 'B';
			}
			eq = 0;
		} else if ( m[li[i]].fi > 2 ) {
			putchar(m[li[i]].se);
		} else {
			putchar(m[li[i]].se);
		}
	}
	pr("\n");
}