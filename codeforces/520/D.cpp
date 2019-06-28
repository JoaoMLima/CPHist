#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000009LL
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
map<ii, int> avaliableCoordToValue;
map<int, ii> avaliableValueToCoord;
map<ii, int> notAvaliable;
vector<ii> pts;

int avaliable(ii coord) {
    if ((avaliableCoordToValue.count({coord.fi-1, coord.se+1}) || notAvaliable.count({coord.fi-1, coord.se+1})) && 
            (!avaliableCoordToValue.count({coord.fi-1, coord.se}) && !notAvaliable.count({coord.fi-1, coord.se})
            && !avaliableCoordToValue.count({coord.fi-2, coord.se}) && !notAvaliable.count({coord.fi-2, coord.se}))) {
                return 0;
        } else if ((avaliableCoordToValue.count({coord.fi, coord.se+1}) || notAvaliable.count({coord.fi, coord.se+1})) && 
            (!avaliableCoordToValue.count({coord.fi-1, coord.se}) && !notAvaliable.count({coord.fi-1, coord.se})
            && !avaliableCoordToValue.count({coord.fi+1, coord.se}) && !notAvaliable.count({coord.fi+1, coord.se}))) {
                return 0;
        } else if ((avaliableCoordToValue.count({coord.fi+1, coord.se+1}) || notAvaliable.count({coord.fi+1, coord.se+1})) && 
            (!avaliableCoordToValue.count({coord.fi+1, coord.se}) && !notAvaliable.count({coord.fi+1, coord.se})
            && !avaliableCoordToValue.count({coord.fi+2, coord.se}) && !notAvaliable.count({coord.fi+2, coord.se}))) {
                return 0;
        }
        return 1;
}


int main(){
    sc("%d\n", &m);
    ll res = 0;
    for(int i = 0; i < m;i++) {
        sc("%d %d", &a, &b);
        notAvaliable[{a, b}] = i;
        pts.pb({a, b});
    }
    for(int i = 0; i < m;i++) {
        //trace(pts[i].fi, pts[i].se);
        if(avaliable(pts[i])) {
            avaliableCoordToValue[pts[i]] = i;
            avaliableValueToCoord[i] = pts[i];
            notAvaliable.erase(pts[i]);
        }
    }
    for(int i = 0; i < m; i++) {
        pair<int, ii> maior;
        if(i & 1) {
            maior = *(avaliableValueToCoord.begin());
        } else {
            maior = *(--avaliableValueToCoord.end());
        }
        //trace("maior", maior.fi+1);
        avaliableValueToCoord.erase(maior.fi);
        avaliableCoordToValue.erase(maior.se);
        res = md(res * m + maior.fi) % mod;

        if (avaliableCoordToValue.count({maior.se.fi-2, maior.se.se}) && !avaliable({maior.se.fi-2, maior.se.se})) {
            int value = avaliableCoordToValue[{maior.se.fi-2, maior.se.se}];
            avaliableValueToCoord.erase(value);
            avaliableCoordToValue.erase({maior.se.fi-2, maior.se.se});
            notAvaliable[{maior.se.fi-2, maior.se.se}] = value;
        }
        if (avaliableCoordToValue.count({maior.se.fi-1, maior.se.se}) && !avaliable({maior.se.fi-1, maior.se.se})) {
            int value = avaliableCoordToValue[{maior.se.fi-1, maior.se.se}];
            avaliableValueToCoord.erase(value);
            avaliableCoordToValue.erase({maior.se.fi-1, maior.se.se});
            notAvaliable[{maior.se.fi-1, maior.se.se}] = value;
        }
        if (avaliableCoordToValue.count({maior.se.fi+2, maior.se.se}) && !avaliable({maior.se.fi+2, maior.se.se})) {
            int value = avaliableCoordToValue[{maior.se.fi+2, maior.se.se}];
            avaliableValueToCoord.erase(value);
            avaliableCoordToValue.erase({maior.se.fi+2, maior.se.se});
            notAvaliable[{maior.se.fi+2, maior.se.se}] = value;
        }
        if (avaliableCoordToValue.count({maior.se.fi+1, maior.se.se}) && !avaliable({maior.se.fi+1, maior.se.se})) {
            int value = avaliableCoordToValue[{maior.se.fi+1, maior.se.se}];
            avaliableValueToCoord.erase(value);
            avaliableCoordToValue.erase({maior.se.fi+1, maior.se.se});
            notAvaliable[{maior.se.fi+1, maior.se.se}] = value;
        }
        if (notAvaliable.count({maior.se.fi-1, maior.se.se-1}) && avaliable({maior.se.fi-1, maior.se.se-1})) {
            int value = notAvaliable[{maior.se.fi-1, maior.se.se-1}];
            avaliableValueToCoord[value] = {maior.se.fi-1, maior.se.se-1};
            avaliableCoordToValue[{maior.se.fi-1, maior.se.se-1}] = value;
            notAvaliable.erase({maior.se.fi-1, maior.se.se-1});
        }
        if (notAvaliable.count({maior.se.fi, maior.se.se-1}) && avaliable({maior.se.fi, maior.se.se-1})) {
            int value = notAvaliable[{maior.se.fi, maior.se.se-1}];
            avaliableValueToCoord[value] = {maior.se.fi, maior.se.se-1};
            avaliableCoordToValue[{maior.se.fi, maior.se.se-1}] = value;
            notAvaliable.erase({maior.se.fi, maior.se.se-1});
        }
        if (notAvaliable.count({maior.se.fi+1, maior.se.se-1}) && avaliable({maior.se.fi+1, maior.se.se-1})) {
            int value = notAvaliable[{maior.se.fi+1, maior.se.se-1}];
            avaliableValueToCoord[value] = {maior.se.fi+1, maior.se.se-1};
            avaliableCoordToValue[{maior.se.fi+1, maior.se.se-1}] = value;
            notAvaliable.erase({maior.se.fi+1, maior.se.se-1});
        }
        
    }
    pr("%lld\n", res);
 	return 0;
}