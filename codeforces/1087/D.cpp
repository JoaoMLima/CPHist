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
int n, a, b, c;
ld m;
vector<int> g[100001];
int vi[100001];

int main(){
    sc("%d %Lf\n", &n, &m);
    memset(vi, 0, sizeof vi);
    for(int i = 0; i < n-1; i++) {
        sc("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    queue<int> q;
    c = 0;
    q.push(1);
    vi[1] = 1;
    while(!q.empty()) {
        int f = q.front(); q.pop();
        if(g[f].size() == 1) {c++;}
        for(int i = 0; i < (int)g[f].size(); i++) {
            if (!vi[g[f][i]]) {
                vi[g[f][i]] = 1;
                q.push(g[f][i]);
            }
        }
    }
    pr("%.15Lf\n", (m/c)*2LL);
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
