#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 998244353
#define modL 998244353ll
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
int pot[200000];
char s[200000];
int acc[200000];
int main(){
    pot[0] = 1;
    for(int i = 1; i < 200000; i++) {
        pot[i] = 2 * pot[i-1];
        if (pot[i] > mod) { pot[i] -= mod;} 
    }
    sc("%d %d\n", &n, &m);
    for(int i = 0; i < 200000 - n; i++) {
        s[i] = '0';
    }
    for(int i = 200000 - n; i < 200000; i++) {
        s[i] = getchar();
    }
    getchar();
    for(int i = 0; i < 200000 - m; i++) {
        acc[i] = 0;
    }
    for(int i = 200000 - m; i < 200000; i++) {
        acc[i] = (getchar() == '1');
    }

    int ex = m;
    for(int i = 1; i < 200000; i++) {
        acc[i] += acc[i-1];
    }
    int r = 0;
    for(int i = 0; i < 200000; i++) {
        ll t = ((ll)acc[i] * (ll)(s[i] == '1') * (ll)pot[200000 - 1 - i]) % modL;
        r = md(r + (int)t);
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