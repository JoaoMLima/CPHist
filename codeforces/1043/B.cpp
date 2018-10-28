#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define getc getchar
#define putc putchar
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
typedef vector<ii> vii;
typedef vector<ll> vll;

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
int li[1001];
int main(){
    sc("%d\n", &n);
    //pr("%d\n", n);
    int ult = 0;
    for(int i = 0; i < n; i++) {
        sc("%d\n", &a);
        li[i] = a - ult;
        ult = a;
    }
    vector<int> resps;
    for(int i = 1; i <= n; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if (li[j] != li[j %  i]) {ok = false;}
        }
        if (ok) {
            resps.pb(i);
        }
    }
    
    pr("%d\n", (int)resps.size());
    pr("%d", resps[0]);
    for(int i = 1; i < resps.size(); i++) {
        pr(" %d", resps[i]);
    }
    pr("\n");
	/*
	//Entrada 1
    while ((ch = getc()) != '\n') {
      s[n++] = ch;
    }
	//Entrada 2
    sc("%d\n", &n);
    for (int i = 0; i < n; i++) {
        sc("%d", li+i);
    }
	//Entrada 3
    sc("%s", &s);
	//Entrada 4
    while(sc("%d\n", &n) != EOF){

    }*/
 	return 0;
}
