#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
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
int n, m, a, b, c, k;


struct item {
    int key, prior, cnt;
    item * l, * r;
    item() { }
    item (int key, int prior) : key(key), prior(prior), l(NULL), r(NULL), cnt(1) { }
    item (item * p) : key(p->key), prior(p->prior), l(p->l), r(p->r), cnt(p->cnt) { }
};
typedef item * pitem;

int cnt (pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt (pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt (t->r);
}

void split (pitem t, int key, pitem & l, pitem & r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split (t->l, key, l, t->l),  r = t;
    else
        split (t->r, key, t->r, r),  l = t;
    upd_cnt(t);
}

void merge (pitem & t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge (l->r, l->r, r),  t = l;
    else
        merge (r->l, l, r->l),  t = r;
    upd_cnt(t);
}

void prtreap(pitem t) {
    if (!t) {
        pr("()");
        return;
    }
    pr("(%d: ", t->key);
    prtreap(t->l);
    pr(", ");
    prtreap(t->r);
    pr(")");
}

pitem treap[10001]; 

int main(){
	sc("%d %d", &n, &k);
    ll s = 0;
    for(int i = 1;i <= 10000; i++) {
        treap[i] = new item(-1000000001, (rand() << 16) + rand());
    }
    priority_queue<pair<ii, ii>, vector<pair<ii, ii> >, greater<pair<ii, ii> > > pq;
    for(int i = 0; i < n; i++) {
        sc("%d %d %d", &a, &b, &c);
        pq.push({{a, 0}, {b, c}});
        if(a+b <= 1000000000) {
            pq.push({{a+b, 1}, {b, c}});
        }
    }
    while(!pq.empty()) {
        pair<ii, ii> p = pq.top();pq.pop();
        pitem l = NULL, m = NULL, r = NULL, t = NULL;
        if(!p.fi.se) {
            split(treap[p.se.se], p.fi.fi-p.se.fi-1, l, r);
            s += cnt(r);
            merge(treap[p.se.se], l, r);
            for(int i = p.se.se-k; i <= p.se.se+k; i++) {
                if(i >= 1 && i <= 10000) {
                    split(treap[i], p.fi.fi-1, l, r);
                    merge(treap[i], new item(p.fi.fi, (rand() << 16) + rand()), r);
                    merge(treap[i], l, treap[i]);
                }
            }
            
        } else {
            for(int i = p.se.se-k; i <= p.se.se+k; i++) {
                if(i >= 1 && i <= 10000) {
                    split(treap[i], p.fi.fi-p.se.fi-1, l, r);
                    split(r, p.fi.fi-p.se.fi, m, r);
                    merge(treap[i], l, r);
                }
            }
        }
        
    }
    pr("%lld\n", s);
 	return 0;
}