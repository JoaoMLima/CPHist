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
#define left(x) ((x<<1)+1)
#define right(x) ((x<<1)+2)

typedef long long ll;
typedef long double ld;
typedef pair<double, double> ii;
typedef vector<int> vi;

void prVector(vi v) {cout << "{";for(int i = 0; i < (int)v.size()-1; i++) {cout << v[i] << ", ";} cout << v[(int)v.size()-1] << "}";}

//Trace dinamico
void trace(vi a) { prVector(a); cout << "\n"; }
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
int s[100000][26];
vi st[4*100000];
int isAccum[4*100000];
void generateStructures() {
    for(int i = 0; i < 4*100000; i++) {
        for(int j = 0; j < 26; j++) {
            st[i].pb(0);
        }
    }
}
void merge(int id) {
    //trace("merge:");
    //trace(st[left(id)]);
    //trace(st[right(id)]);
    for(int i = 0; i < 26; i++)
        st[id][i] = st[left(id)][i] + st[right(id)][i];
}
void propagate(int id, int l, int r) {
    if (l == r || !isAccum[id]) return;
    int m = (l+r)>>1;
    int j = (isAccum[id]-1) ? 0 : 25;
    for(int i = 0; i < 26; i++){
        st[left(id)][i] = 0;
        st[right(id)][i] = 0;
    }
    vi v = st[id];
    for(int i = l; i <= m;) {
        while (!v[j]) j += (isAccum[id]-1) ? 1 : -1;
        int mini = min(v[j], m+1-i);
        st[left(id)][j] += mini;
        i += mini;
        v[j] -= mini;
    }
    for(int i = m+1; i <= r;) {
        while (!v[j]) j += (isAccum[id]-1) ? 1 : -1;
        int mini = min(v[j], r+1-i);
        st[right(id)][j] += mini;
        i += mini;
        v[j] -= mini;
    }
    isAccum[left(id)] = isAccum[id];
    isAccum[right(id)] = isAccum[id];
    isAccum[id] = 0;
}
void build(int id, int l, int r) {
    if (r < l) return;
    if (l == r) {
        for(int i = 0; i < 26; i++)
            st[id][i] = s[l][i];
    } else {
        int m = (l+r)>>1;
        build(left(id), l, m);
        build(right(id), m+1, r);
        merge(id);
    }
}
vi query(int id, int l, int r, int i, int j) {
    //recInit(id, l, r, i, j);
    vi resp(26, 0);
    if (r < l || i > r || j < l) {//recEnd(resp);
        return resp;}
    if (l >= i && r <= j) {
        //recEnd(st[id]);
        return st[id];
    } else {
        propagate(id, l, r);
        int m = (l+r)>>1;
        vi va = query(left(id), l, m, i, j);
        vi vb = query(right(id), m+1, r, i, j);
        //trace(va);
        //trace(vb);
        for(int k = 0; k < 26; k++)
            va[k] += vb[k];
        //recEnd(va);
        return va;
    }
}
vi update(int id, int l, int r, int i, int j, vi v, int type) {
    //prTabs();trace(v);
    //recInit(id, l, r, i, j, type);
    if (r < l || i > r || j < l) {//recEnd(v);
        return v;}
    propagate(id, l, r);
    int index = (type) ? 0 : 25;
    //trace("index:", index);
    if (l >= i && r <= j) {
        for(int k = 0; k < 26; k++){
            st[id][k] = 0;
        }
        for(int k = l; k <= r;) {
            while (!v[index]) index += (type) ? 1 : -1;
            int mini = min(v[index], r+1-k);
            st[id][index] += mini;
            k += mini;
            v[index] -= mini;
        }
        isAccum[id] = type+1;
    } else {
        int m = (l+r)>>1;
        v = update(left(id), l, m, i, j, v, type);
        v = update(right(id), m+1, r, i, j, v, type);
        merge(id);
    }
    //trace(st[id]);
    //recEnd(v);
    return v;
}
int n, q, a, b, c;
int main(){
    generateStructures();
    sc("%d %d\n", &n, &q);
    for(int i = 0; i < n; i++) {
        char ch = getchar();
        s[i][ch-'a']++;
    }
    build(0, 0, n-1);
    //prVector(st[1]);
    //prVector(st[2]);
    //prVector(st[0]);
    
    for(int i = 0; i < q; i++) {
        sc("%d %d %d", &a, &b, &c);
        vi r = query(0, 0, n-1, a-1, b-1);
        //trace(r);
        r = update(0, 0, n-1, a-1, b-1, r, c);
        //trace(r);
    }
    
    
    for(int i = 0; i < n; i++) {
        vi r = query(0, 0, n-1, i, i);
        for(int j = 0; j < 26; j++) {
            if (r[j] != 0) {
                putchar('a'+j);break;
            }
        }
    }putchar('\n');
    return 0;
}
