#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam - 1];
#define range(n) for (int i = 0; i < n; i++)
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
typedef pair<int, vector<int>> piv;
int n, m, q, k, t, a, b, c, x, y, z, w;
char s[100];
char ch;
int main()
{
	sc("%d\n", &n);
	int m = 0;
	while (n--)
	{
		m = 0;
		ch = getchar();
    int d = 0;
    int lc = 0;
    int uc = 0;
		while (ch != '\n')
		{
      if (ch >= 'a' && ch <= 'z')
        lc++;
      else if (ch >= 'A' && ch <= 'Z')
        uc++;
      else
        d++;
			s[m++] = ch;
			ch = getchar();
		}
    if (!lc && !uc) {
      s[0] = 'a'; s[1] = 'A';
    } else if (!lc && !d) {
      s[0] = 'a'; s[1] = '0';
    } else if (!uc && !d) {
      s[0] = 'A'; s[1] = '0';
    } else if (!lc && uc > d) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          s[i] = 'a';
          break;
        }
      }
    } else if (!uc && lc > d) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
          s[i] = 'A';
          break;
        }
      }
    } else if (!d && uc > lc) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
          s[i] = '0';
          break;
        }
      }
    } else if (!lc) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
          s[i] = 'a';
          break;
        }
      }
    } else if (!uc) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
          s[i] = 'A';
          break;
        }
      }
    } else if (!d) {
      for(int i = 0; i < m; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
          s[i] = '0';
          break;
        }
      }
    }
    for(int i = 0; i < m; i++) {
      putchar(s[i]);
    }putchar('\n');
	}

	return 0;
}