#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) (x) % mod
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
typedef vector<double> vd;

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
vector<ii> li;
int main(){
    sc("%d %d\n", &n, &m);
    for (int i = 0; i < n; i++) {
        sc("%d", &a);
        if(a) {
            li.pb({i-m+1, i+m-1});
        }
    }
    int r = 0;
    int end = -1;
    int i = -1;
    //trace(li[0].fi, li[0].se, li[1].fi, li[1].se, li[2].fi, li[2].se);
    while(end < n-1) {
        a = i;
        while(i+1 < li.size() && li[i+1].fi <= end+1) {
            i++;
        }
        //trace(a, i, end);
        r++;
        if (i == a) {
            pr("-1\n");
            return 0;
        }
        end = li[i].se;
    }
    pr("%d\n", r);
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
