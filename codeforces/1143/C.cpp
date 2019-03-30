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
int filhos [100001];
int filhosRespeitam [100001];
int respeitaPai [100001];
int p[100001];


int main(){
	memset(filhos, 0, sizeof filhos);
	memset(filhosRespeitam, 0, sizeof filhosRespeitam);
	memset(p, -1, sizeof p);
	sc("%d", &n);
	set<int> removivel;
	for(int i = 0; i < n; i++) {
		sc("%d %d", &a, &b);
		if (a != -1) {
			respeitaPai[i+1] = !b;
			if (!b) filhosRespeitam[a]++;
			p[i+1] = a;
		}
	}
	for(int i = 1; i <= n; i++) {
		//trace(i, p[i], filhosRespeitam[i], respeitaPai[i]);
		if(p[i] != -1 && filhosRespeitam[i] == 0 && !respeitaPai[i]) {
			removivel.insert(i);
		}
	}
	if(removivel.empty()) {
		pr("-1\n");return 0;
	}
	while(!removivel.empty()) {
		int i = *(removivel.begin());
		removivel.erase(i);
		pr("%d ", i);
	}
	pr("\n");

 	return 0;
}
