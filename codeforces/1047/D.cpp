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
#define ps push
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
int val[8];
ll n, m, a, b, c, d;
int fin = 0, ini = 0;
int n1 = 0, n2 = 0;
int zero = 0;
int eq = 1;

int main()
{
	sc("%I64d %I64d", &n, &m);
    if (m < n) {swap(m, n);}
    if (n == 1) {
        if (m % 6 <= 3) {pr("%I64d\n", 0+(m/6)*6);}
        else if ( m % 6 == 4) {pr("%I64d\n", 2+(m/6)*6);}
        else {pr("%I64d\n", 4+(m/6)*6);}
    } else if (n == 2) {
        if (m == 2) {pr("0\n");}
        else if ( m == 3) {pr("4\n");}
        else if ( m == 4) {pr("8\n");}
        else if(m == 5){pr("10\n");}
        else if(m == 6){pr("12\n");}
        else if(m == 7){pr("12\n");}
        else {
            pr("%I64d\n", n*m);
        }
    }
    else  {
        pr("%I64d\n", ((n*m) >> 1) << 1);
    }
    
	return 0;
}