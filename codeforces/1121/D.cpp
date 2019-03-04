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

map<int, int> s;
map<int, int> sa;

int li[500001];
int freq[2][2000002];

int k;
int main(){
	memset(freq, 0, sizeof freq);
	sc("%d %d %d %d", &m, &k, &n, &b);
	for(int i = 1; i <= m; i++) {
		sc("%d", li+i);
	}
	for(int i = 0; i < b; i++) {
		sc("%d", &a);
		if(s.count(a)) {
			s[a]++;
		} else {
			s[a] = 1;
		}
	}
	int il = 0, ir = 0;
	for(int i = 0; i < n; i++) {
		int dacerto  = true;
		while(ir < m-((n-1-i)*k)) {
			freq[1][li[++ir]]++;
		}
		while(il < k*i) {
			freq[0][li[++il]]++;
		}
		
		for(map<int, int>::iterator it = s.begin(); it != s.end(); it++) {
			//trace(il, ir, it->fi, freq[0][it->fi], freq[1][it->fi]);
			if(freq[1][it->fi] - freq[0][it->fi] <  it->se) {
				dacerto = false;break;
			}
		}
		if(!dacerto) continue;
		pr("%d\n", m-(n*k));
		int falta = k-b;
		for(int j = k*i+1; j <= m-((n-1-i)*k); j++) {
			if(sa[li[j]] < s[li[j]] ) {
				sa[li[j]]++;
			} else if(falta) {
				sa[li[j]]++;
				falta--;
			} else {
				pr("%d ", j);
			}
		}
		pr("\n"); return 0;
	}
	pr("-1\n");
 	return 0;
}
