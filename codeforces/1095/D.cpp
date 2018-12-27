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
int li[200010][2];
int v[200010];
int main(){
    memset(v, 0, sizeof v);
    sc("%d\n", &n);
    for(int i = 1; i <= n; i++) {
        sc("%d %d\n", &a, &b);
        li[i][0] = a;
        li[i][1] = b;
    }
    if (n == 3) {
        pr("1 2 3\n");
    } else {
    int p = 0;
    int i = 1;
    while(!v[i]) {
        v[i] = 1;
        if(p) {
            pr(" ");
        } else {
            p = 1;
        }
        if(li[li[i][0]][0] == li[i][1] || li[li[i][0]][1] == li[i][1]) {
            pr("%d", li[i][0]);
            i = li[i][0];
        } else {
            pr("%d", li[i][1]);
            i = li[i][1];
        }
    }
    
    pr("\n");
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