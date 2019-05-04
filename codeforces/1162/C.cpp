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
int n, m, a, b, c, k;
int li[100007];
int vi[100007];
int rmr[100007];
int rml[100007];
int main(){
    for(int i = 0; i < 100007; i++) {
        vi[i] = 0; li[i] = 3;
        rmr[i] = 0;rml[i] = 0;
    }
    
	sc("%d %d", &n, &k);
    li[1]--; li[n]--;
    for(int i = 0; i < k; i++) {
        sc("%d\n", &a);
        if (!vi[a]) li[a]--;
        if (vi[a-1] && !rmr[a-1]) {
            li[a-1]--;rmr[a-1] = 1;
        }
        if (vi[a+1] && !rml[a+1]) {
            li[a+1]--;rml[a+1] = 1;
        }
        vi[a] = 1;
    }
    int res = 0;
    for(int i = 1; i <= n; i++) {
        res += li[i];
    }
    pr("%d\n", res);
 	return 0;
}
