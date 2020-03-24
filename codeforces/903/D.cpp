#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
 
typedef long long ll;
typedef pair<int, int> ii;
 
struct node {
	ll v = 0, acum = 0, qtd = 0;
	node *l = NULL, *r = NULL;
};
 
typedef node* pNode;
 
void update2(pNode p, ll l, ll r, ll i, ll v) {
	if (l > i || r < i) return;
	p->qtd += v;
	if (l == r) return;
	ll m = (l+r)/2LL;
	if (i <= m) {
	    if (p->l == NULL) p->l = new node;
	    update2(p->l, l, m, i, v);
	    return;
	}
	
	if (p->r == NULL) p->r = new node;
	update2(p->r, m+1, r, i, v);
}
 
void update(pNode p, ll l, ll r, ll i, ll j, ll v) {
	if (l > j || r < i) return;
	if (l >= i && r <= j) {
		p->acum += v;
		return;
	}
	ll m = (l+r)/2LL;
	if (p->l == NULL) p->l = new node;
	if (p->r == NULL) p->r = new node;
	update(p->l, l, m, i, j, v);
	update(p->r, m+1, r, i, j, v);
	p->v += v*(min(j, r) - max(i, l) + 1);
}
 
ll query(pNode p, ll l, ll r, ll i, ll j) {
	if (l > j || r < i) return 0LL;
	if (l >= i && r <= j) {
		return p->v+p->acum*(r-l+1) + p->qtd;
	}
	ll m = (l+r)/2LL;
	if (p->l == NULL) p->l = new node;
	if (p->r == NULL) p->r = new node;
	return p->acum*(min(j, r) - max(i, l) + 1) + query(p->l, l, m, i, j) + query(p->r, m+1, r, i, j);
}
 
void print128(__int128 num) {
    
    if (num < 0) {
        pr("-");
        num = -num;
    }
	if (num / 10) {
		print128(num/10);
	}
	pr("%d", (int)(num % 10));
}
 
pNode root = new node;
 
int n, a, b, c;
int main(){
	sc("%d", &n);
	__int128 r = 0LL;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		v.pb(a);
		r += query(root, 1, 1000000010, 1, a);
		//pr("%lld\n",r);
		update(root, 1, 1000000010, a+2, 1000000010, 1);
		update2(root, 1, 1000000010, a+2, 1);
	}
 
	//pr("%lld %lld\n", query(root, 1, 1000000000, 1, 1000000000), r);
	
	for(int x : v) {
		update(root, 1, 1000000010, x+2, 1000000010, -1);
		update2(root, 1, 1000000010, x+2, -1);
	}
	//pr("%lld %lld\n", query(root, 1, 1000000000, 1, 1000000000), r);
	for(int i = n-1; i >= 0; i--) {
		r -= query(root, 1, 1000000010, 1, v[i]);
		//pr("%lld\n",r);
		update(root, 1, 1000000010, v[i]+2, 1000000010, 1);
		update2(root, 1, 1000000010, v[i]+2, 1);
	}
	print128(r);
	pr("\n");
	//pr("%lld\n", r);
 	return 0;
}