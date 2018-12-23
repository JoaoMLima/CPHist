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
int n = 0, m, a, b, c;
//vector<int> g[maxn]; 
char ch;
char s[50];
char s1[50];
int main(){
    ch = getchar();
    while (ch >= 'a' && ch  <= 'z') {
      s[n++] = ch;
      ch = getchar();
    }
    if (n & 1) {
        int j = 0;
        for(int i = 0; i < n/2; i++) {
            s1[j++] = s[i];
            s1[j++] = s[n-1-i];
        }
        s1[j++] = s[n/2];
    } else {
        int j = 0;
        for(int i = 0; i < n/2; i++) {
            s1[j++] = s[n-1-i];
            s1[j++] = s[i];
        }
    }
    for(int i = n-1; i >= 0; i--) {
        putchar(s1[i]);
    }pr("\n");
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
