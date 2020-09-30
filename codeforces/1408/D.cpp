#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

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

vector<ii> robbers;
vector<ii> light;
vector<ii> tmp1;
vector<ii> tmp2;

ii dif[2007];
int nxt[2007];


int st[4*2007];
int query(int id, int l, int r, int i, int j) {
	if (l > j || r < i) return 0;
	if (l >= i && r <= j) return st[id];
	int m = (l+r)/2;
	return max(query(L(id), l, m, i, j), query(R(id), m+1, r, i, j));
}

void update(int id, int l, int r, int i, int v) {
	if (l == r) {st[id] = v;return;}
	int m = (l+r)/2;
	if (i <= m) update(L(id), l, m, i, v);
	else update(R(id), m+1, r, i, v);
	st[id] = max(st[L(id)], st[R(id)]);
}



int n, m, k, a, b, c;
int main(){
	sc("%d %d\n", &n, &m);
	for(int i = 0; i < n; i++) {
		sc("%d %d", &a, &b);
		tmp1.pb({a, b});
	}
	for(int i = 0; i < m; i++) {
		sc("%d %d", &a, &b);
		tmp2.pb({-b, -a});
	}
	sort(tmp1.begin(), tmp1.end());
	robbers.pb(tmp1[0]);
	for (ii p : tmp1) {
		if (p.se >= robbers.back().se) continue;
		robbers.pb(p);
	}
	sort(tmp2.begin(), tmp2.end());
	light.pb({-tmp2[0].se, -tmp2[0].fi});
	for (ii p : tmp2) {
		if (-p.se <= light.back().fi) continue;
		light.pb({-p.se, -p.fi});
	}
	int j = sz(light)-1;
	int best = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	for(int i = sz(robbers)-1; i >= 0; i--) {
		while(j && light[j-1].fi >= robbers[i].fi) {
			j--;
		}
		if (light[j].fi >= robbers[i].fi) {
			nxt[i] = j;
			pq.push({light[j].fi-robbers[i].fi + 1, i});
			update(0, 0, 2002, i, light[j].se - robbers[i].se + 1);
			best = max(best, light[j].se - robbers[i].se + 1);
		} else {
			nxt[i] = -1;
		}
	}
	int difx = 0;
	int dify = 0;
	//trace("best", best);
	

	while(!pq.empty()) {
		ii f = pq.top(); pq.pop();
		//trace("f:", f.fi, f.se);
		difx = f.fi;
		if (nxt[f.se] == sz(light)-1) {
			update(0, 0, 2002, f.se, 0);
			dify = query(0, 0, 2002, 0, 2002);
			//trace("difx:", difx, "dify:", dify);
			best = min(best, difx+dify);
			
		} else {
			nxt[f.se]++;
			update(0, 0, 2002, f.se, light[nxt[f.se]].se - robbers[f.se].se + 1);
			dify = query(0, 0, 2002, 0, 2002);
			//trace("difx2:", difx, "dify2:", dify);
			best = min(best, difx+dify);
			pq.push({light[nxt[f.se]].fi-robbers[f.se].fi + 1, f.se});
		}
	//trace("best", best);
	}
	pr("%d\n", best);
	/*
	for(ii tmp : robbers) {
		trace("rob: {", tmp.fi, tmp.se, "}");
	}
	for(ii tmp : light) {
		trace("lig: {", tmp.fi, tmp.se, "}");
	}
	int best = max(0, light[0].se-robbers[sz(robbers)-1].se+1);
	
	/*
	int i = 0, j = 0;
	int x = 0;
	while(i < sz(robbers)) {
		while (j != sz(light)-1 && light[j].se >= robbers[i].se) {
			trace("1 {", robbers[i].fi, robbers[i].se, "} {", light[i].fi, light[i].se, "}");
			j++;
		}
		x = light[j].fi;
		trace("2 {", robbers[i].fi, robbers[i].se, "} {", light[i].fi, light[i].se, "}", x);
		dif[i].fi = max(0, x - robbers[i].fi + 1);
		i++;
	}
	i = sz(robbers)-1, j = sz(light)-1;
	int y = 0;
	while(i >= 0) {
		while (j && light[j].fi >= robbers[i].fi) {
			trace("3 {", robbers[i].fi, robbers[i].se, "} {", light[i].fi, light[i].se, "}");
			j--;
		}
		y = light[j].se;
		trace("4 {", robbers[i].fi, robbers[i].se, "} {", light[i].fi, light[i].se, "}", y);
		dif[i].se = max(0, y - robbers[i].se+1);
		i--;
	}
	
	sort(dif, dif+sz(robbers));
	trace("dif: {", dif[0].fi, dif[0].se, "}");
	int best = dif[sz(robbers)-1].fi;
	for(i = sz(robbers)-2; i >= 0; i--) {
		trace("dif: {", dif[i].fi, dif[i].se, "}");
		best = min(best, dif[i].fi + dif[i].se);
		dif[i].se = max(dif[i].se, dif[i+1].se);
	}
	pr("%d\n", best);
	
	*/

 	return 0;
}
