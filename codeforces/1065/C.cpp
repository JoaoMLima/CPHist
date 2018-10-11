#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod
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
int n, m, a, b, c, d, k;
//vector<int> g[maxn]; 
int li[200001];
int main(){
	memset(li, 0, sizeof li);
	sc("%d %d", &n, &k);
	int mini = 200001;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		li[a]++;
		mini = min(mini, a);
	}
	//trace(mini);
	int accum = 0;
	int distinct = 0;
	int r = 0;
	for(int i = 200000; i > mini; i--) {
		//trace("i:", i);
		//trace(accum, li[i], accum + li[i], k);
		if (accum + distinct + li[i] > k) {
			//trace("r++");
			r++;
			accum = 0;
		}
		accum += li[i] + distinct;
		distinct += li[i];
	}
	if (accum != 0) {
		r++;
	}
	pr("%d\n", r);
}
