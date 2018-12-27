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
int n = 0, m, a, b, c, k;
//vector<int> g[maxn]; 

int main(){
    sc("%d %d\n", &n, &k);
    
    if (k > n) {
        pr("NO\n"); return 0;
    }
    int p = 1073741824;
    vector<int> v;
    while(k && p) {
        if (p > n) {p >>= 1;}
        else if(k - 1 > n-p){ p >>= 1;}
        else {k--; n-=p; v.pb(p);}
    }
    if(n != 0) {
        pr("NO\n"); return 0;
    }
    pr("YES\n");
    pr("%d", v[0]);
    
    for(int i = 1; i < (int)v.size(); i++) {
        pr(" %d", v[i]);
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
