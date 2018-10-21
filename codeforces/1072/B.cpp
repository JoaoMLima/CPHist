#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((x) % mod)
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
int li1[100000];
int li2[100000];
int li3[100000];
int main(){
    sc("%d\n", &n);
    for(int i = 0; i < n-1; i++) {
        sc("%d", li1+i);
    }
    for(int i = 0; i < n-1; i++) {
        sc("%d", li2+i);
    }
    li3[n-1] = 0;
    for(int i = n-2; i >= -1; i--) {
        if (i == -1) {
            pr("YES\n");
            pr("%d", li3[0]);
            for(int i = 1; i < n; i++) {
                pr(" %d", li3[i]);
            }
            pr("\n");
            return 0;
        }
        //trace("a", li3[i+1], li1[i], li2[i], 2 | li3[i+1], 2 & li3[i+1]);
        if (((0 | li3[i+1]) == li1[i]) && ((0 & li3[i+1]) == li2[i])) {
            li3[i] = 0;
        } else if (((1 | li3[i+1]) == li1[i]) && ((1 & li3[i+1]) == li2[i])) {
            li3[i] = 1;
        } else if (((2 | li3[i+1]) == li1[i]) && ((2 & li3[i+1]) == li2[i])) {
            li3[i] = 2;
        } else if (((3 | li3[i+1]) == li1[i]) && ((3 & li3[i+1]) == li2[i])) {
            li3[i] = 3;
        } else {
            break;
        }
        //trace("li3:", li3[i]);
    }
    li3[n-1] = 1;
    for(int i = n-2; i >= -1; i--) {
        if (i == -1) {
            pr("YES\n");
            pr("%d", li3[0]);
            for(int i = 1; i < n; i++) {
                pr(" %d", li3[i]);
            }
            pr("\n");
            return 0;
        }
        if (((0 | li3[i+1]) == li1[i]) && ((0 & li3[i+1]) == li2[i])) {
            li3[i] = 0;
        } else if (((1 | li3[i+1]) == li1[i]) && ((1 & li3[i+1]) == li2[i])) {
            li3[i] = 1;
        } else if (((2 | li3[i+1]) == li1[i]) && ((2 & li3[i+1]) == li2[i])) {
            li3[i] = 2;
        } else if (((3 | li3[i+1]) == li1[i]) && ((3 & li3[i+1]) == li2[i])) {
            li3[i] = 3;
        } else {
            break;
        }
    }
    li3[n-1] = 2;
    for(int i = n-2; i >= -1; i--) {
        if (i == -1) {
            pr("YES\n");
            pr("%d", li3[0]);
            for(int i = 1; i < n; i++) {
                pr(" %d", li3[i]);
            }
            pr("\n");
            return 0;
        }
        if (((0 | li3[i+1]) == li1[i]) && ((0 & li3[i+1]) == li2[i])) {
            li3[i] = 0;
        } else if (((1 | li3[i+1]) == li1[i]) && ((1 & li3[i+1]) == li2[i])) {
            li3[i] = 1;
        } else if (((2 | li3[i+1]) == li1[i]) && ((2 & li3[i+1]) == li2[i])) {
            li3[i] = 2;
        } else if (((3 | li3[i+1]) == li1[i]) && ((3 & li3[i+1]) == li2[i])) {
            li3[i] = 3;
        } else {
            break;
        }
    }
    li3[n-1] = 3;
    for(int i = n-2; i >= -1; i--) {
        if (i == -1) {
            pr("YES\n");
            pr("%d", li3[0]);
            for(int i = 1; i < n; i++) {
                pr(" %d", li3[i]);
            }
            pr("\n");
            return 0;
        }
        if (((0 | li3[i+1]) == li1[i]) && ((0 & li3[i+1]) == li2[i])) {
            li3[i] = 0;
        } else if (((1 | li3[i+1]) == li1[i]) && ((1 & li3[i+1]) == li2[i])) {
            li3[i] = 1;
        } else if (((2 | li3[i+1]) == li1[i]) && ((2 & li3[i+1]) == li2[i])) {
            li3[i] = 2;
        } else if (((3 | li3[i+1]) == li1[i]) && ((3 & li3[i+1]) == li2[i])) {
            li3[i] = 3;
        } else {
            break;
        }
    }
    pr("NO\n");
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
