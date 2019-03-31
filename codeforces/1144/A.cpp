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

int main(){
	sc("%d\n", &n);
	for(int i = 0;i < n; i++) {
	    vector<int> v(26, 0);
		char ch = getchar();
		int m = 0;
		char menor = ch;
		char maior = ch;
		int repitiu = 0;
		
		while(ch != '\n') {
		    if (v[ch-'a']) repitiu = 1;
			if (ch < menor) { menor = ch;}
			if (ch > maior) {maior = ch;}
			v[ch-'a']++;
			m++;
			ch = getchar();
		}
		//trace(maior, menor, maior-menor, m);
		if (maior - menor + 1 == m && !repitiu) {
			pr("Yes\n"); 
		} else {
			pr("No\n");
		}
	}
 	return 0;
}
