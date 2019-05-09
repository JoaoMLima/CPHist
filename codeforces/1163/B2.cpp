#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
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
int qtd[100010];
int bitQtd[100010];
int freq[100010];
int li[100010];

int query(int i) {
    int s = 0;
    while(i) {
        s += bitQtd[i];
        i -= i&(-i);
    } return s;
}

void update(int i, int v) {
    while(i < 100010) {
        bitQtd[i] += v;
        i += i&(-i);
    }
}

int minimal() {
    int l = 0; int r = 100009;
    while(l < r) {
        int m = (l+r)/2;
        int v = query(m);
        //trace(l, r, m, v);
        if (v > 0) {
            r = m;
        } else {
            l = m+1;
        }
    }
    //trace("l1:", l);
    return l;
}

int maximal() {
    int l = 0; int r = 100009;
    int vTotal = query(100009);
    while(l < r) {
        int m = (l+r)/2;
        int v = query(m);
        //trace(l, r, m, v, vTotal);
        if (v == vTotal) {
            r = m;
        } else {
            l = m+1;
        }
    }
    //trace("l2:", l);
    return l;
}

int main(){
	sc("%d\n", &n);
    int resp = 1;
    forn(i, n) {
        sc("%d", &a);
        //trace("a:", a);
        if (freq[a] != 0) {
            update(freq[a], -1);
        }
        //trace("aqui1");
        freq[a]++;
        update(freq[a], 1);
        int mini = minimal();
        //trace("aqui2");
        int maxi = maximal();
        //trace("mini:", mini, "maxi:", maxi);
        //trace("aqui3");
        update(mini, -1);
        if (mini != 1) {
            update(mini-1, 1);
        }
        if (minimal() == maximal()) {
            resp = i+1;
        }
        update(mini, 1);
        if (mini != 1) {
            update(mini-1, -1);
        }
        update(maxi, -1);
        if (maxi != 1) {
            update(maxi-1, 1);
        }
        if (minimal() == maximal()) {
            resp = i+1;
        }
        update(maxi, 1);
        if (maxi != 1) {
            update(maxi-1, -1);
        }
    }
    pr("%d\n", resp);

 	return 0;
}
