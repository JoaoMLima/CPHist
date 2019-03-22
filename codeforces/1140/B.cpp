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
int n, t,m, a, b, c;
//vector<int> g[maxn]; 

char s[100];
int main(){
	sc("%d\n", &t);
    while(t--) {
        sc("%d\n", &n);
        int mini = n-1;
        for(int i = 0; i < n; i++) {
            s[i] = getchar();
        }
        getchar();
        int i = 0;
        while(s[i] == '<') {
            i++;
        }
        mini = min(mini, i);
        i = n-1;
        while(s[i] == '>') {
            i--;
        }
        mini = min(mini, n-1-i);
        pr("%d\n", mini);
    }
    
    
 	return 0;
}
