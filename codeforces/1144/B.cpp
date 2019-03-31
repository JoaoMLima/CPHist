#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
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
int n, m, a, b, c;
vi pares;
vi impares;
int main(){
	sc("%d",&n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (a & 1) impares.pb(a);
		else pares.pb(a);
	}
	sort(pares.begin(), pares.end());
	sort(impares.begin(), impares.end());
	int mini = min((int)pares.size(), (int)impares.size());
	int sum = 0;
	int achou = 0;
	for(int i = (int)impares.size()-1-mini; i>= 0; i--) {
		if (achou) sum += impares[i];
		achou = 1;
	}
	for(int i = (int)pares.size()-1-mini; i>= 0; i--) {
		if (achou) sum += pares[i];
		achou = 1;
	}
	pr("%d\n",sum);
 	return 0;
}
