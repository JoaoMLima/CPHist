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
typedef pair<int, vector<int> > piv;
int val[8];
int n, m, a, b, c, d;
int fin = 0, ini = 0;
int n1 = 0, n2 = 0;
int li[200000];
int zero = 0;
int main(){
  sc("%d\n", &n);
  int dp[n][8];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 8; j++) {
      dp[i][j] = -1;
    }
  }
  for(int i = 0; i < n; i++) {
    sc("%d ", &a);
    char ch = getchar();
    int k = 0;
    while (ch != '\n') {
      if (ch == 'A') {
        k+= 1;
      } else if (ch == 'B') {
        k+= 2;
      } else {
        k+= 4;
      }
      ch = getchar();
    }
    dp[i][k] = a;
  li[i] = k;
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < i; j++) {
      for(int k = 0; k < 8; k++) {
        if (dp[j][k] != -1) {
          if(dp[i][k | li[i]] == -1) {
            dp[i][k | li[i]] = dp[j][k] + dp[i][li[i]];
          } else {
            dp[i][k | li[i]] = min(dp[i][k | li[i]], dp[j][k] + dp[i][li[i]]);
          }
        }
      }
    }
  }
  int mini = INT_MAX;
  for(int i = 0; i < n; i++) {
    if (dp[i][7] != -1) {
      mini = min(mini, dp[i][7]);
    }
  }
  if (mini == INT_MAX) {
    pr("-1\n"); return 0;
  }
  pr("%d\n", mini);
  return 0;
}
