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
int freq1[200001];
int freq2[200001];
vi l1;
vi l2;
int main(){
	memset(freq1, 0, sizeof freq1);
	memset(freq2, 0, sizeof freq2);
	sc("%d",&n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (!freq1[a]) {
			l1.pb(a);
			freq1[a]++;
		} else if(!freq2[a]) {
			l2.pb(a);
			freq2[a]++;
		} else {
			pr("NO\n"); return 0;
		}
	}
	pr("YES\n");
	sort(l1.begin(), l1.end());
	sort(l2.begin(), l2.end());
	pr("%d\n", (int)l1.size());
	for(int i = 0; i < (int)l1.size(); i++) {
		pr("%d ", l1[i]);
	}pr("\n");

	pr("%d\n", (int)l2.size());
	for(int i = (int)l2.size()-1; i>= 0; i--) {
		pr("%d ", l2[i]);
	}pr("\n");
 	return 0;
}
