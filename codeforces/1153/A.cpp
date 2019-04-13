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
int n, m, a, b, c, t;

int main(){
	sc("%d %d", &n, &t);
	int te = 1e9;
	int bus;
	for(int i = 0; i < n; i++) {
		sc("%d %d", &a, &b);
		if (a >= t) {
			if (a < te) {
				bus = i+1;
			}
			te = min(te, a);
		} else {
			if (a + ((t-a) / b)*b + (((t-a) % b) ? b : 0) < te) {
				bus = i+1;
			}
			te = min(te, a + ((t-a) / b)*b + (((t-a) % b) ? b : 0));
		}
	}
	pr("%d\n", bus);
 	return 0;
}
