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
int n, m, a, b, c, d;
int fin = 0, ini = 0;
int n1 = 0, n2 = 0;
int cri[15000001];
int cri2[15000001];
int li[300000];
int zero = 0;
int eq = 1;
int main()
{
	for (int i = 0; i < 15000001; i++)
	{
		cri[i] = i;
    cri2[i] = 0;
	}
	for (int i = 2; i < 3873; i++)
	{
		if (cri[i] == i)
		{
			for (int j = i * i; j < 15000001; j += i)
			{
				if (cri[j] == j)
				{
					cri[j] = i;
				}
			}
		}
	}
	sc("%d", &n);
	for (int i = 0; i < n; i++)
	{
		//trace1(i);
		sc("%d", &li[i]);
	}
	int maxi = 0;
  
  for(int i = 0; i < n; i++) {
    int div;
    while (li[i] != 1) {
      int d1 = cri[li[i]];
      a = 1;
      while(cri[li[i]] == d1) {
        a *= d1;
        li[i] /= d1;
      }
      cri2[a]++;
    }
  }
  for (int i = 15000000; i >= 2; i--)
	{
    if (cri2[i] < n) {
      maxi = max(maxi, cri2[i]);
    }
    cri2[i/cri[i]] += cri2[i];
	}
  if(maxi == 0) {
    pr("-1\n");
    return 0;
  }
  //pr("maxi: %d\n", maxi);
	pr("%d\n", n - maxi);
	return 0;
}