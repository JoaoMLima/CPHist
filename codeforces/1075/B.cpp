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
int li[200000];
int pass[100000];
int tax[100000];
int qt[100000];
int main(){
    memset(qt, 0, sizeof qt);
    int np = 0;
    int nt = 0;
    sc("%d %d\n", &n, &m);
    for (int i = 0; i < n+m; i++) {
        sc("%d", li+i);
    }
    for (int i = 0; i < n+m; i++) {
        sc("%d", &a);
        if(a) {
            tax[nt++] = li[i];
        } else {
            pass[np++] = li[i];
        }
    }
    int ip = 0;
    int it = 0;
    for (int i = 0; i < n; i++) {
        if (it == m-1) {
            qt[it]++;
        } else {
            while(it < m-1 && abs(pass[i] - tax[it+1]) < abs(pass[i] - tax[it])) {
                it++;
            }
            qt[it]++;
        }
    }
    pr("%d", qt[0]);
    for(int i = 1; i < m; i++) {
        pr(" %d", qt[i]);
    }pr("\n");

	/*
	//Entrada 1
    while ((ch = getc()) != '\n') {
      s[n++] = ch;
    }
	//Entrada 2
    
	//Entrada 3
    sc("%s", &s);
	//Entrada 4
    while(sc("%d\n", &n) != EOF){

    }*/
 	return 0;
}
