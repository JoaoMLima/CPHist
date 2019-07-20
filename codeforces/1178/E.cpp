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
char ch;
char s[1000010];
int main(){
	n = 0;
	ch = getchar();
	while(ch != '\n') {
		s[n++] = ch;
		ch = getchar();
	}
	vector<char> resp;
	int i = 0, j = n-1;
	while(j-i+1 > 3) {
		int a = 0, b = 0, c = 0;
		if (s[i] == 'a') a++;
		else if (s[i] == 'b') b++;
		else c++;
		if (s[i+1] == 'a') a++;
		else if (s[i+1] == 'b') b++;
		else c++;
		if (s[j] == 'a') a++;
		else if (s[j] == 'b') b++;
		else c++;
		if (s[j-1] == 'a') a++;
		else if (s[j-1] == 'b') b++;
		else c++;
		if (a >= 2) resp.pb('a');
		else if (b >= 2) resp.pb('b');
		else resp.pb('c');
		i += 2;
		j -= 2;
	}
	int extra = 0;
	if (j-i+1 > 0) {
		resp.pb(s[i]); extra++;
	}
	for(int i = 0; i < (int)resp.size(); i++) {
		pr("%c", resp[i]);
	}
	for(int i = (int)resp.size()-1-extra; i >= 0; i--) {
		pr("%c", resp[i]);
	}
	pr("\n");
 	return 0;
}
