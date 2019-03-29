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
int n, m, k, a, b, c;
//vector<int> g[maxn];
ll sum[1000002];
ii li[1000002];



int main(){
    priority_queue<int, vector<int>, greater<int> > s;
    memset(sum, 0, sizeof sum);
    sc("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
        sc("%d %d", &a, &b);
        li[i] = {b, -a};
    }
    sort(li, li+n);
    int j= n-1;
    for(int i = 1000000; i >= 1; i--) {
        
        sum[i] = sum[i+1];
        if(i <= 8) {
            //trace("sumi", i, sum[i]);
        }
        
        while(li[j].fi >= i) {
            //trace(i, j, li[j].fi, sum[i]);
            s.push(-li[j].se);
            sum[i] -= (li[j].se)+0LL;
            if(s.size() > k) {
                sum[i] -= (s.top())+0LL;
                s.pop();
            }
            if(j == 0) break;
            j--;
            
            //trace(i, sum[i]);
        }
        if(j == 0 || i == 0) {break;}
        
    }
    ll maxi = -1LL;
    for(int i = 1; i <= 1000000; i++) {
        maxi = max(maxi, i*sum[i]);
    }
    pr("%lld\n", maxi);
 	return 0;
}