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
//vector<int> g[maxn]; 
int l[100002];

int main(){
    sc("%d %d\n", &n, &m);
    int maxi = -1;
    int cmax = 0;
    ll tot = 0;
    for(int i = 0; i < n; i++) {
        sc("%d", l+i);
        tot += l[i];
    }
    sort(l, l+n);
    if(n == 1) {pr("0\n"); return 0;}
    ll s = 0;
    int alt = 0;
    int extras = 0;
    for(int i = 0; i < n; i++) {
        //trace(i, l[i], alt);
        if(l[i] == alt) {
            extras = max(extras - 1, 0);
        }
        if(l[i] > alt) {
            extras += (l[i] - 1) - alt;
            alt = l[i];
        }
        
         //trace("ex:",extras);
    }
    //trace(tot, n, max(extras, 0));
    int nze = 0;
    for(int i = 0; i < n; i++) {
        if(l[i] != 0) {nze++;}
    }
    pr("%lld\n", tot - (nze + max(extras, 0)));
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