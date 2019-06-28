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

struct Node {
	int vl, vm, vr, liml, limr;
	Node *l, *r; //Nós filhos
	Node(int v = 0, int i = 0) {
        vl = v; vm = v; vr = v;
        l = NULL; r = NULL;
        liml = i; limr = i;
    }
    Node(Node *_l, Node *_r) {
        l = _l; r = _r;
        liml = l->liml;
        limr = r->limr;
        vl = (l->vl == l->limr - l->liml + 1) ? (l->vl +r->vl) : l->vl;
        vr = (r->vr == r->limr - r->liml + 1) ? (l->vr +r->vr) : r->vr;
        vm = max(max(max(vl, vr), max(l->vm, r->vm)), l->vr + r->vl);
    }
};

typedef Node *pNode;

pNode build(int l, int r) {
    if (l == r)
        return new Node(0, l);
    int m = (l + r) / 2;
    return new Node(build(l, m), build(m+1, r));
}

pNode update(pNode node, int l, int r, int i) {
    if (l == r)
        return new Node(1, l);
    int m = (l + r) / 2;
    if (i <= m) {
        return new Node(update(node->l, l, m, i), node->r);
    }
    else {
        return new Node(node->l, update(node->r, m+1, r, i));
    }
}

pair<int, ii> query(pNode node, int l, int r, int i, int j) {
	if (r < i || l > j) return {0, {0, 0}};
	if (l >= i && r <= j) return {node->vl, {node->vm, node->vr}};
	int m = (l+r)>>1;
    pair<int, ii> ql = query(node->l, l, m, i, j);
    pair<int, ii> qr = query(node->r, m + 1, r, i, j);
    pair<int, ii> result;
    result.fi = (ql.fi == m-l+1) ? (ql.fi + qr.fi) : ql.fi;
    result.se.se = (qr.se.se == r-m) ? (ql.se.se + qr.se.se) : qr.se.se;
    result.se.fi = max(max(max(ql.se.fi, qr.se.fi), max(result.fi, result.se.se)), ql.se.se + qr.fi);
    return result;
}

pNode root[100010];


map<int, int> ma;
int alturas[100010];
set<int> he;
ii li[100010];

int main(){
	for(int i = 0; i < 100000; i++) {
        root[i] = NULL;
    }
    sc("%d", &n);
    for(int i = 0; i < n; i++) {
        sc("%d", &a);
        li[i] = {a, i};
        he.insert(a);
    }
    int ct = 0;
    while(!he.empty()) {
        int maxi = *(--he.end());
        alturas[ct] = maxi;
        ma[maxi] = ct++;
        he.erase(maxi);
    }
    sort(li, li+n, greater<ii>());
    root[0] = build(0, n-1);
    root[ma[li[0].fi]] = update(root[ma[li[0].fi]], 0, n-1, li[0].se);
    for(int i = 1; i < n; i++) {
        root[ma[li[i].fi]] = update(root[ma[li[i-1].fi]], 0, n-1, li[i].se);
    }

    sc("%d", &m);

    for(int i = 0; i < m; i++) {
        sc("%d %d %d", &a, &b, &c);
        int l = 0, r = ct-1; 
        while(r >= l) {
            int m = (l+r)>>1;
            if(query(root[m], 1, n, a, b).se.fi >= c) {
                r = m-1;
            } else {
                l = m+1;
            }
        }
        if (l == 0) {
            pr("%d\n", alturas[0]);
        } else if (r == ct-1) {
            pr("0\n");
        } else {
            pr("%d\n", alturas[l]);
        }
    }
 	return 0;
}