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
int n, m, a, b, c;
ii li[3];
//vector<int> g[maxn]; 

int main(){
    for(int i = 0; i < 3; i++) {
        sc("%d %d", &a, &b);
        li[i] = {a, b};
    }
    sort(li, li+3);
    vector<ii> v;
    for(int i = li[0].fi; i < li[1].fi; i++) {
        v.pb({i, li[0].se});
    }
    for(int i = li[2].fi; i > li[1].fi; i--) {
        v.pb({i, li[2].se});
    }
    for(int i = min(li[0].se, min(li[1].se, li[2].se)); i <= max(li[0].se, max(li[1].se, li[2].se)); i++) {
        v.pb({li[1].fi, i});
    }
    pr("%d\n", (int)v.size());
    for(int i = 0; i < (int)v.size(); i++) {
        pr("%d %d\n", v[i].fi, v[i].se);
    }
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
