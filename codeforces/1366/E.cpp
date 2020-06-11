#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MOD 998244353LL

typedef long long ll;
typedef pair<int, int> ii;


int p[200007];
int vi[200007];
int mini[200007];
int maxi[200007];
int li1[200007];
int li2[200007];
ii li3[200007];
int des[200007];
ii res[200007];

int find(int a) {
	if(p[a] == a) return a;
	return p[a] = find(p[a]);
}

void uni(int a, int b) {
	a = find(a), b = find(b);
	if (a != b) {
		if (rand() &1) {
			p[a] = b;
			mini[b] = min(mini[b], mini[a]);
			maxi[b] = max(maxi[b], maxi[a]);
		} else {
			p[b] = a;
			mini[a] = min(mini[b], mini[a]);
			maxi[a] = max(maxi[b], maxi[a]);
		}
	}
}


int main(){
	int n, m;
	int ok = 1;
	sc("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		sc("%d", li1+i);
		p[i] = i;
		mini[i] = i;
		maxi[i] = i;
		li3[i] = {-li1[i], i};
	}
	for(int i = 0; i < m; i++) {
		sc("%d", li2+i);
	}
	int k = m-1;
	for(int i = n-1; i >= 0; i--) {
		if (k < 0) break;
		if (li1[i] == li2[k]) {
			des[i] = 1;
			k--;
		}
	}
	if (k >= 0) {
		pr("0\n");
		return 0;
	}
	sort(li3, li3+n);
	for(int i = 0; i < n; i++) {
		ii x = li3[i];
		if(x.se && vi[x.se-1]) uni(x.se, x.se-1);
		if(x.se < n-1 && vi[x.se+1]) uni(x.se, x.se+1);
		int f = find(x.se);
		if (des[x.se]) res[x.se] = {mini[f], maxi[f]};
		vi[x.se] = 1;
	}

	ii last = {-1, -1};
	
	ll qtd = 1;
	for(int i = 0; i < n; i++) {
		if (des[i]) {
			ii r = res[i];
			if (last == mp(-1, -1)){
				if (r.fi != 0) {
					ok = 0;
					break;
				}
			} else{
				int xl = max(last.fi, r.fi);
				int xr = min(last.se, i-1);
				int u = max(xr-xl+2, 0);
				qtd = (qtd*u)%MOD;
			}
			

			last = {i+1, r.se};
		}
	}
	if (last.se != n-1) {
		ok = 0;
	}
	if (!ok) pr("0\n");
	else pr("%lld\n", qtd);

	
 	return 0;
}
