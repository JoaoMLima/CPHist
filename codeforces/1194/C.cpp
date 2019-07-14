#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
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
int n, m;
char s[100];
char t[100];
int mapped[100];

void insert(map<char, int> &p, char c) {
	if (p.count(c)) p[c]++;
	else p[c] = 1;
}
int remove(map<char, int> &p, char c) {
	if(p.count(c)) {
		//trace(p[c]);
		if(p[c] == 1) {
			p.erase(c);
		} else {
			p[c]--;
		}
		return 1;
	}
	return 0;
}
int main(){
	sc("%d\n", &n);
	while(n--) {
		memset(mapped, 0, sizeof mapped);
		map<char, int> p;
		int ns = 0, nt = 0, np = 0;
		char ch = getchar();
		while(ch != '\n') {
			s[ns++] = ch;
			ch = getchar();
		}
		ch = getchar();
		while(ch != '\n') {
			t[nt++] = ch;
			ch = getchar();
		}
		ch = getchar();
		while(ch != '\n') {
			insert(p, ch);
			ch = getchar();
		}
		int i = 0, j = 0;
		for(; i < ns && j < nt; ) {
			if (t[j] == s[i]) {
				mapped[j] = 1;
				i++; j++;
			} else {
				j++;
			}
		}
		//trace(i, j, ns, nt);
		if (i != ns) {
			pr("NO\n");
		} else {
			j = 0;
			int certo = 1;
			for(; j < nt;j++) {
				if(!mapped[j] && !remove(p, t[j])) {
					certo = 0;
					break;
				}
			}
			if(certo) pr("YES\n");
			else pr("NO\n");
		}
	}
 	return 0;
}
