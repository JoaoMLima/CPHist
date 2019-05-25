#include <bits/stdc++.h>
using namespace std;
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
#define md(x, mo) ((((x) % mo) + mo) % mo)
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
int n, x;
char ch;
char s[10010];
char resp[10010];
char res1[10010];
char res2[10010];
char res3[10010];

pair<ll, ll> extended_gcd(ll a, ll b) {
    if (!b) return {1, 0};
    pair<ll, ll> t = extended_gcd(b, a % b);
    return {t.se, t.fi - t.se * (a / b)};
}

ll modinverse(ll a, ll m) {
    return (extended_gcd(a, m).fi % m + m) % m;
}

ll findMinX(vector<ll> &num, vector<ll> &rem) {
    ll prod = 1; 
    for (int i = 0; i < (int)num.size(); i++) 
        prod *= num[i];
    
    ll result = 0;
    for (int i = 0; i < (int)num.size(); i++) { 
        ll pp = prod / num[i]; 
        result += rem[i] * modinverse(pp, num[i]) * pp; 
    }
    return result % prod; 
}

int main(){
    int n = 0;
    sc("%c", &ch);
    while(ch >= 'a' && ch <= 'z') {
        s[n++] = ch;
        sc("%c", &ch);
    }
    pr("? ");
    for(int i = 0; i < n; i++) {
        pr("%c", (char)(i % 23) + 'a');
    }pr("\n");fflush(stdout);
    pr("? ");
    for(int i = 0; i < n; i++) {
        pr("%c", (char)(i % 24) + 'a');
    }pr("\n");fflush(stdout);
    pr("? ");
    for(int i = 0; i < n; i++) {
        pr("%c", (char)(i % 25) + 'a');
    }pr("\n");fflush(stdout);

    for(int i  = 0; i < n; i++) {
        sc("%c", &ch);
        res1[i] = ch-'a';
    }sc("%c", &ch);
    for(int i  = 0; i < n; i++) {
        sc("%c", &ch);
        res2[i] = ch-'a';
    }sc("%c", &ch);
    for(int i  = 0; i < n; i++) {
        sc("%c", &ch);
        res3[i] = ch-'a';
    }sc("%c", &ch);
    pr("! ");
    for(int i = 0; i < n; i++) {
        vector<ll> a = {23, 24, 25};
        vector<ll> b = {res1[i], res2[i], res3[i]};
        //pr("%lld %lld %lld\n", b[0], b[1], b[2]);
        //pr("%d\n", findMinX(a, b));
        resp[findMinX(a, b)] = s[i];
    }
    for(int i = 0; i < n; i++) {
        pr("%c", resp[i]);
    }pr("\n");fflush(stdout);
    return 0;
}
