#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << (i==tam-1) ? "\n" : " "
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
int n, m, a, b, c;
int room[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int main(){
	sc("%d\n", &n);
	for(int i = 0; i < n; i++) {
		char ch = getchar();
		if(ch == 'L') {
			for(int i = 0; i < 10; i++) {
				if(!room[i]) {room[i] = 1; break;}
			}
		} else if (ch == 'R') {
			for(int i = 9; i >= 0; i--) {
				if(!room[i]) {room[i] = 1; break;}
			}
		} else {
			int a = (ch-'0');
			room[a] = 0;
		}
	}
	for(int i = 0; i < 10; i++) {
		putchar((char)(room[i]+'0'));
	}pr("\n");
 	return 0;
}
