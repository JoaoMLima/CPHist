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

int li[700];

int dpl(int, int);
int dpr(int, int);

int gcd(int a, int b) {
    return (a == 0) ? b : gcd(b % a, a);
}
char dplt[700][700];
char dprt[700][700];

int dpl(int l, int r) {
    //recInit(0, l, r);
    if(l > r) return 1;
    if(dplt[l][r] == -1) {
        for(int i = l; i <= r; i++) {
            if(gcd(li[r+1], li[i]) > 1 && dpl(l, i-1) && dpr(i+1, r)){
                dplt[l][r] = 1;
                return dplt[l][r];
            } 
        }
        dplt[l][r] = 0;
    }
    //recEnd((int)dplt[l][r]);
    return dplt[l][r];
}

int dpr(int l, int r) {
    //recInit(1, l, r);
    if(l > r) return 1;
    if(dprt[l][r] == -1) {
        for(int i = l; i <= r; i++) {
            if(gcd(li[l-1], li[i]) > 1 && dpl(l, i-1) && dpr(i+1, r)){
                dprt[l][r] = 1;
                return dprt[l][r];
            }
        }
        dprt[l][r] = 0;
    }
    //recEnd((int)dprt[l][r]);
    return dprt[l][r];
}

bool dp() {
    for(int i = 0; i < n; i++) {
        if (i == 0) {
            if(dpr(1, n-1)) return true;
        } else if (i == n-1) {
            if(dpl(0, n-2)) return true;
        } else {
            if(dpl(0, i-1) && dpr(i+1, n-1)) return true;
        }
    }
    return false;
}

int main(){
    memset(dplt, -1, sizeof dplt);
    memset(dprt, -1, sizeof dprt);
    sc("%d", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", li+i);
    }
    if(dp()) {
        pr("YES\n");
    } else {
        pr("NO\n");
    }
 	return 0;
}