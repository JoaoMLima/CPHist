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
int n = 0, k, m = 0, a, b, c;
//vector<int> g[maxn]; 
int li[100];
char s[101];
char ch;
int main(){
    ch = getchar();
    while (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z') {
      s[m++] = ch;
      //trace(ch, m-1);
      ch = getchar();
    }
    char s2[125];
    int a = (m / 20) + ((m % 20) ? 1 : 0);
    int b = (m / a) + ((m % a) ? 1 : 0);
    int r = (b - (m % b))% b;
    //trace(b, m % b, b - (m % b));
    //trace(m, a, r);
    pr("%d %d\n", a, b);
    for(int i = 0; i < m;) {
        if(n % (b+1) == b-1) {
            if(r > 0) {
                r--; s2[n++] = '*';
            } else {
                s2[n++] = s[i++];
            }
            s2[n++] = '\n';
            continue;
        }
        if (i >= m) { break;}
        s2[n++] = s[i++];
    }
    for(int i = 0; i < n; i++) {
        putchar(s2[i]);
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
