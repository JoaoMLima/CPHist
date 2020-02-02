#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAXN 300010

typedef long long ll;
typedef pair<int, int> ii;

int a, b, c;
struct vt {
	int f = -1, s = -1;
	
	void pb(int x)  {
		if (f != -1) s = x;
		else f = x;
	}
	int size() {
		if (f == -1) return 0;
		if (s == -1) return 1;
		return 2;
	}
	int get(int x) {
		return (x) ? s : f;
	}
};
vt li[MAXN];
int val[MAXN];
int obig[MAXN];
int p[MAXN];
int op[MAXN];
int cnt[MAXN];
int accum = 0;
int usados[MAXN];


int find(int a) {
	if (a == p[a]) return a;
	return p[a] = find(p[a]);
}
void auxUnit(int a, int b) {
	if (a == b)return;
	if (rand()&1) {
		p[a] = b;
		cnt[b] += cnt[a];
		if (obig[a] != -1) obig[b] = obig[a];
	} else {
		p[b] = a;
		cnt[a] += cnt[b];
		if (obig[b] != -1) obig[a] = obig[b];
	}
}

void unit(int a, int b) {
	a = find(a); b = find(b);
	if (a != b) {
		auxUnit(a, b);
		if (op[a] && op[b]) {
			a = find(op[a]); b = find(op[b]);
			auxUnit(a, b);
		} else if (op[a]) {
			a = find(op[a]); b = find(b);
			op[b] = a;
		} else if (op[b]) {
			a = find(op[b]); b = find(b);
			op[b] = a;
		}
	}
	
}



void remove(int x) {
	if (x < 1) return;
	x = find(x);
	if (usados[x]) {
		accum -= cnt[x];
		usados[x] = false;
	}
}

void insert(int x) {
	if (x < 1) return;
	x = find(x);
	if (!usados[x]) {
		accum += cnt[x];
		usados[x] = 1;
	}
}

void obi(int x, int v) {
	if (x < 1) return;
	x = find(x);
	obig[x] = v;

	if (op[x] != -1) {
		int y = find(op[x]);
		obig[y] = !v;
	}
}

void defineop(int a, int b) {
	a = find(a); b = find(b);
	if (op[a] && op[b]) {
		unit(a, op[b]);
		unit(b, op[a]);
	} else if (op[a]) {
		unit(b, op[a]);
		op[b] = a;
	} else if (op[b]){
		unit(a, op[b]);
		op[a] = b;
	}
	else {
		op[a] = b;
		op[b] = a;
	}
	a = find(a); b = find(b);
	if (obig[a] != -1) obi(b, !obig[a]);
	if (obig[b] != -1) obi(a, !obig[b]);
}

int main(){
	int t, m, n, k;
	sc("%d %d\n", &n, &k);
	for(int i = 1; i < MAXN; i++) {
		cnt[i] = 1;
		p[i] = i;
		obig[i] = -1;
	}
	for(int i = 1; i <= n; i++) {
		char ch = getchar();
		if (ch == '1') val[i] = 1;
	}
	for(int i = 1; i <= k; i++) {
		sc("%d", &a);
		for(int j = 0; j < a; j++) {
			sc("%d", &b);
			li[b].pb(i);
		}
		
	}

	for(int i = 1; i <= n; i++) {
		//pr("i: %d\n", i);
		//pr("val[i]: %d li[i].size(): %d\n", val[i], (int)li[i].size());
		if (val[i]) {
			if (li[i].size() == 0) {}
			else if (li[i].size() == 1) {
				int x = find(li[i].get(0));
				remove(x);
				insert(op[x]);
				obi(x, 0);
			} else {
				int x = find(li[i].get(0));
				int y = find(li[i].get(1));

				if (x != y) {
					remove(x);
					remove(y);
					remove(op[x]);
					remove(op[y]);
					unit(x, y);
					int z = find(x);
					if (obig[z] == 1) {
						insert(z);
						obi(op[z], 0);
					} else if (obig[z] == 0){
						insert(op[z]);
						obi(op[z], 1);
					} else {
						if (op[z] != -1) {
							int w = find(op[z]);
							if (cnt[w] < cnt[z]) {
								insert(w);
							} else {
								insert(z);
							}
						}
					}
				}
			}
		} else {
			if (li[i].size() == 0) {}
			else if (li[i].size() == 1) {
				int x = find(li[i].get(0));
				insert(x);
				obi(x, 1);
				remove(op[x]);
			} else {
				int x = find(li[i].get(0));
				int y = find(li[i].get(1));
				remove(x);
				remove(y);
				remove(op[x]);
				remove(op[y]);
				defineop(x, y);
				x = find(x);
				y = find(op[x]);
				if (obig[x] == 0) {
					insert(y);
				} else if (obig[x] == 1) {
					insert(x);
				} else {
					if (cnt[y] < cnt[x]) {
						insert(y);
					} else {
						insert(x);
					}
				}
			}
		}
		pr("%d\n", accum);
	}
	for(int i = 1; i < MAXN; i++) {
		cnt[i] = 1+rand();
		p[i] = i;
		obig[i] = -1;
	}
 	return 0;
}
