#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) (x) % mod
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
int n, m;
ll a;
int li[26];
//vector<int> g[maxn]; 
int main(){
    string men;
    int mini = 1, maxi  = 1000000000-1;
    sc("%d", &n);
    pr("%d %d\n", 0,  0);
    fflush(stdout);
    cin >> men;
    for(int i = 1; i < n; i++) {
        string s;
        int med = (mini+maxi)/2;
        pr("%d %d\n", med, med);
        fflush(stdout);
        cin >> s;
        if (s == men) {
            mini = med+1;
        } else {
            maxi = med-1;
        }
    }
    pr("%d %d %d %d\n", mini, mini-1, mini-1, mini);
    fflush(stdout);
 	return 0;
}
