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
typedef unsigned int ui;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ui> vui;

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

struct Node {
    int v = 0;
    Node* L = NULL;
    Node* R = NULL;
};

typedef Node* pNode;
int query(pNode node, int l, int r, int i, int j) {
    if (r < i || l > j) return 0;
    if (l >= i && r <= j) return node->v;
    if (!node->L) node->L = new Node;
    if (!node->R) node->R = new Node;
    int m = (l+r) >> 1;
    return max(query(node->L, l, m, i, j), query(node->R, m+1, r, i, j));
}
void update(pNode node, int l, int r, int i, int v) {
    //trace(l, r, i, v);
    if (l == r) {node->v = max(v, node->v); return;}
    if (!node->L) node->L = new Node;
    if (!node->R) node->R = new Node;
    int m = (l+r) >> 1;
    if (i <= m) update(node->L, l, m, i, v);
    else update(node->R, m+1, r, i, v);
    node->v = max(node->L->v, node->R->v);
}
pNode roots[100010];
struct trio {int a, b, c;};

int main(){
    int n, m, a, b, c;
    sc("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        roots[i] = new Node;
    }
    int r = 0;
    vector<trio> edges;
    for(int i = 0; i < m; i++) {
        sc("%d %d %d", &a, &b, &c);
        edges.pb({a, b, c});
    }
    for(int i = (int)edges.size()-1; i >= 0; i--) {
        int qr = 1 + query(roots[edges[i].b], 0, 100000, edges[i].c, 100000);
        r = max(r, qr);
        update(roots[edges[i].a], 0, 100000, edges[i].c, qr);
    }
    pr("%d\n", r);
    return 0;
}