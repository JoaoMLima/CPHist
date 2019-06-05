#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007LL
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

//vector<int> g[maxn];

vector<vi> multiply(vector<vi>& A, vector<vi>& B) {
  int n = A.size(), m = A[0].size(), k = B[0].size();
  vector<vi> C(n, vi(k, 0));
  
  for(int i = 0; i < n; i++)
    for(int j = 0; j < k; j++)
      for(int l = 0; l < m; l++)
        C[i][j] = (1LL * A[i][l] * B[l][j] + C[i][j]) % mod;

  return C;
}

vector<vi> power(vector<vi>& A, int k) {
  int n = A.size();
  vector<vi> resp(n, vi(n)), B = A;

  for(int i = 0; i < n; i++) resp[i][i]=1;

  while(k) {
    if(k & 1) resp = multiply(resp, B);
    B = multiply(B, B); k >>= 1; 
  }
  return resp;
}

int main(){
    int n, b, r, m, a;
	sc("%d %d %d %d", &n, &b, &r, &m);
    vi qtd(10, 0);
    vector<vi> res(1, vi(m, 0));
    vector<vi> expo(m, vi(m, 0));
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        qtd[a]++;
        res[0][a%m]++;
    }
    for(int i = 0; i < m; i++) {
        for(int j = 1; j <= 9; j++) {
            expo[i][(i*10+j)%m] += qtd[j];
        }
    }
    expo = power(expo, b-1);
    res = multiply(res, expo);
    pr("%d\n", res[0][r]);
 	return 0;
}
