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
int n, m, a, b, c, t, q, k;
int l[300001];
int co[300001];

int main(){
	memset(co, -1, sizeof co);
	set<ii> s;
	sc("%d", &n);
	sc("%d", &a);
	l[0] = a;
	co[0] = a;
	for(int i = 1; i < n; i++) {
		sc("%d", &a);
		l[i] = a;
		if(co[i-1] != a) {
			co[i] = 0;
		} else {
			co[i] = a;
		}
	}
	int maxi = 0;
	for(int i = 1; i < n; i++) {
		int le = 0, r = i-1;
		if(co[i] == l[i]) {
			continue;
		}
		while(le <= r) {
			//trace(le, r);
			int mid = (le+r)/2;
			//trace(mid, co[mid], l[i]);
			if(co[mid] == 0 || co[mid] != l[i]) {
				r = mid-1;
			} else {
				le = mid+1;
			}
		}
		//trace(le, r);
		//trace(i, le, "a");
		maxi = max(maxi, i-max(le, 0));
	}
	pr("%d\n", maxi);
 	return 0;
}
