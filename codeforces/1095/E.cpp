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
char li[1000010];
int dpr[1000010];
int dpl[1000010];
int main(){
    sc("%d\n", &n);
    for(int i = 0;i < n; i++) {
        li[i] = getchar();
    }
	
    int a = 0;
    for(int i = 0; i < n; i++) {
        if(a >= 0) {
            if (li[i] == '(') {
            a++;
            } else {
                a--;
            }
        }
        dpl[i] = a;
    }
    a = 0;
    for(int i = n-1; i >= 0; i--) {
        if(a >= 0) {
            if (li[i] == ')') {
            a++;
            } else {
                a--;
            }
        }
        dpr[i] = a;
    }
    int tot = 0;
    for(int i = 0; i < n; i++) {
        if(li[i] == '(') {
            if(i == 0) { a = 0;}
            else {
                if(dpl[i-1] == -1) {continue;}
                a = dpl[i-1];
            }
            if(i == n-1) { b = 1;}
            else {
                if(dpr[i+1] == -1) {continue;}
                b = dpr[i+1]+1;
            }
        } else {
            if(i == 0) { a = 1;}
            else {
                if(dpl[i-1] == -1) {continue;}
                a = dpl[i-1]+1;
            }
            if(i == n-1) { b = 0;}
            else {
                if(dpr[i+1] == -1) {continue;}
                b = dpr[i+1];
            }
        }
        //trace(a, b);
        if(b-a == 0) {
            tot++;
        }
    }
    pr("%d\n", tot);
    /*
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
