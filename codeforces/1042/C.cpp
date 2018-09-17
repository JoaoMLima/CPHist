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
  sc("%I64d\n", &n);
  for(int i = 0; i < n; i++) {
    sc("%I64d", &li[i]);
  }
  int neg = 0;
  int pos = 0;
  int minneg = INT_MAX;
  for(int i = 0; i < n; i++) {
    if (li[i] > 0) {
      pos++;
    } else if (li[i] < 0) {
      if(!neg) {
        minneg = li[i];
      } else {
        minneg = max(minneg, li[i]);
      }
      neg++;
    } else {
      zero++;
    }
  }
  //pr("%d %d\n", pos, neg);
  
  if(pos || neg > 1) {
    int falta = (neg & 1) + zero;
    int exc = 0;
    int ult = -1;
    int ult2 = -1;
    for(int i = 0; i < n; i++) {
        //pr("%d %d %d %d t\n", exc, (neg&1), li[i], minneg);
         if (!exc && (neg&1) && li[i] == minneg) {
           exc = 1;
           if (ult2 != -1) {
             pr("1 %d %d\n", ult2+1, i+1);

           }
           if (falta == 1) {
             pr("2 %d\n", i+1);
           }
           falta--;
           ult2 = i;
         } else if (li[i] == 0) {
           if (ult2 != -1) {
             pr("1 %d %d\n", ult2+1, i+1);
           }
           if (falta == 1) {
             pr("2 %d\n", i+1);
           }
           falta--;
           ult2 = i;
         } else {
           if (ult != -1) {
             pr("1 %d %d\n", ult+1, i+1);
           }
           ult = i;
         }
       }
    } else {
       for(int i = 1; i < n; i++) {
         pr("1 %d %d\n", i, i+1);
       }
    }
  return 0;
}
