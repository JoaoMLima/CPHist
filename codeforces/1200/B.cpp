#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << (i==tam-1) ? "\n" : " "
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
int n, m, a, b, c, t, k;
int he[110];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d %d %d", &n, &m, &k);
		memset(he, 0, sizeof he);
		for(int i = 0; i < n; i++) {
			sc("%d", he+i);
		}
		int printou = 0;
		for(int i = 0; i < n-1; i++) {
			int desejada = max(0, he[i+1]-k);
			//trace(desejada, he[i], he[i+1], m);
			if(he[i] < desejada) {
				int dif = min(desejada-he[i], m);
				he[i] += dif;
				m -= dif;
			} else {
				m += he[i]-desejada;
				he[i] -= he[i]-desejada;
			}
			if(he[i+1]- he[i] > k) {
				pr("NO\n");
				printou = 1;
				break;
			}
		}
		if(!printou) pr("YES\n");
	}
 	return 0;
}
