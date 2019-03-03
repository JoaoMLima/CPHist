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
//vector<int> g[maxn]; 

int li[1000];
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	int maxi = 0;
	sort(li, li+n);
	for(int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if(i != j) {
				int ct = 1;
				int s = li[i]+li[j];
				int l = i+1, r = j-1;
				while(r > l) {
					if(li[l] + li[r] > s) {
						r--;
					} else if(li[l] + li[r] < s) {
						l++;
					} else {
						ct++; l++; r--;
					}
				}
				maxi = max(maxi, ct);
			}
		}
	}
	pr("%d\n", maxi);
 	return 0;
}
