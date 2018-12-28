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
int validl[26];
int validr[26];
char s[200010];

int main(){
    sc("%d\n", &n);
    for(int i = 0; i < 26; i++) {
        validl[i] = -1;
        validr[i] = n;
    }
    for(int i = 0; i < n; i++) {
        s[i] = getchar();
    }
    for(int i = 0; i < 26; i++) {
        int valid = 1;
        for(int j = 0; j < n; j++) {
            if(s[j] == 'a'+i && valid) {
                validl[i] = j;
            } else {
                valid = 0;
            }
        }
    }
    for(int i = 0; i < 26; i++) {
        int valid = 1;
        for(int j = n-1; j >= 0; j--) {
            if(s[j] == 'a'+i && valid) {
                validr[i] = j;
            } else {
                valid = 0;
            }
        }
    }
    ll r = 1LL;
    for(int i = 0; i < 26; i++) {
        //trace(i+'a', validl[i], validr[i]);
        if(validl[i]< validr[i]) {
            if(validl[i] == -1 && validr[i] != n) {
                r  = r + (ll)(n-validr[i]);
            } else if (validl[i] != -1 && validr[i] == n) {
                r  = r + ((ll)validl[i])+1LL;
            } else if (validl[i] != -1 && validr[i] != n) {
                r = r + ((n-validr[i])+1LL)*((validl[i])+2LL) -1LL;
            }
        } else {
            ll ln = (ll)n;
            r = r + ((ln +1LL)*ln)>> 1;
        }
        r = ((r % 998244353LL)+998244353LL)%998244353LL;
    }
    pr("%lld\n", r);
 	return 0;
}
