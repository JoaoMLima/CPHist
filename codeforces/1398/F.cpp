#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}

int n, a;

set<ii> int0;
set<ii> int1;
vector<ii> pararemover0;
vector<ii> pararemover1;
int main(){
	sc("%d\n", &n);
    int l1 = -1, l0 = -1;
    for(int i = 1; i <= n; i++) {
        char ch = getchar();
        if (ch == '0') {
            if (l1 != -1) {int1.insert({l1, i-1}); l1 = -1;}
            if (l0 == -1) l0 = i;
        } else if (ch == '1') {
            if (l0 != -1) {int0.insert({l0, i-1}); l0 = -1;}
            if (l1 == -1) l1 = i;
        } else {
            if (l0 == -1) l0 = i;
            if (l1 == -1) l1 = i;
        }
    }
    if (l0 != -1) int0.insert({l0, n});
    if (l1 != -1) int1.insert({l1, n});
    for(int i = 1; i <= n; i++) {
        int r = 0;
        int resp = 0;
        auto f1 = int1.begin(); auto f0 = int0.begin();
        while(f1 != int1.end() || f0 != int0.end()) {
            while(f1 != int1.end() && f1->se - max(r+1,  f1->fi)+1 < i) {
                if (f1->se - f1->fi + 1 == i) pararemover1.pb(*f1);
                f1 = next(f1);
            }

            while(f0 != int0.end() && f0->se - max(r+1,  f0->fi)+1 < i) {
                if (f0->se - f0->fi + 1 == i) pararemover0.pb(*f0);
                f0 = next(f0);
            }
            //trace(i, "{", f0->fi, f0->se, "}, {", f1->fi, f1->se, "}");

            if (f1 != int1.end() && f0 != int0.end()) {
                if (f1->fi < f0->fi) {
                    r = max(f1->fi, r+1)+i-1;
                } else {
                    r = max(f0->fi, r+1)+i-1;
                }
                resp++;
            } else if (f1 != int1.end()) {
                r = max(f1->fi, r+1)+i-1;
                resp++;
            } else if (f0 != int0.end()) {
                r = max(f0->fi, r+1)+i-1;
                resp++;
            }
           // trace(r);
        }
        while(!pararemover1.empty()) {
            int1.erase(pararemover1.back());
            pararemover1.pop_back();
        }
        while(!pararemover0.empty()) {
            int0.erase(pararemover0.back());
            pararemover0.pop_back();
        }
        if (i > 1) pr(" ");
        pr("%d", resp);
    }pr("\n");
    
 	return 0;
}
