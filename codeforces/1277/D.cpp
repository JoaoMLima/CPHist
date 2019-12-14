#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
struct hsh{
	ll f = 0LL, s = 0LL, t = 0LL;
	bool operator < (hsh h) const {
		if(f != h.f) return f < h.f;
		if(s != h.s) return s < h.s;
		return t < h.t;
	}
};
hsh hsl[200010];

int n, t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		set<hsh> s;
		set<hsh> dpl;
		int dif = 0;
		int vira = 0;
		int so0 = 0;
		int so1 = 0;
		vector<int> l01;
		vector<int> l10;
		for(int i = 0; i < n; i++) {
			vector<char> v;
			hsh hs, hi;
			char ch = getchar();
			while(ch != '\n') {
				v.pb(ch);
				ch = getchar();
			}
			ll fp = 59, sp = 83, tp = 263;
			ll fa = 1, sa = 1, ta = 1;
			for(int j = (int)v.size()-1; j >= 0; j--) {
				hi.f += v[j]*fa;
				hi.s += v[j]*sa;
				hi.t += v[j]*ta;
				fa *= fp; sa *= sp; ta *= tp;
			}
			fp = 59, sp = 83, tp = 263;
			fa = 1, sa = 1, ta = 1;
			for(int j = 0; j < (int)v.size(); j++) {
				hs.f += v[j]*fa;
				hs.s += v[j]*sa;
				hs.t += v[j]*ta;
				fa *= fp; sa *= sp; ta *= tp;
			}
			hsl[i] = hs;
			if(v[0] != v[(int)v.size()-1]) {
				if (s.count(hi)) {
					dpl.insert(hi);
					dpl.insert(hs);
				} else {
					s.insert(hs);
				}
				vira = 1;
				
				if(v[0] == '1') {dif--;l10.pb(i);}
				else {dif++;l01.pb(i);}
			} else {
				if(v[0] == '0') so0 = 1;
				else so1 = 1;
			}
		}
		if(!vira && so1 && so0) {
			pr("-1\n");
		} else {
			vector<int> trocas;
			if(dif > 1) {
				dif = abs(dif);
				for(int j = 0; j < l01.size(); j++) {
					if(dif > 1 && !dpl.count(hsl[l01[j]])) {
						trocas.pb(l01[j]);
						dif -= 2;
					}
				}
			} else if (dif < -1) {
				dif = abs(dif);
				for(int j = 0; j < l10.size(); j++) {
					if(dif > 1 && !dpl.count(hsl[l10[j]])) {
						trocas.pb(l10[j]);
						dif -= 2;
					}
				}
			}
			pr("%d\n", (int)trocas.size());
			for(int i = 0; i < (int)trocas.size(); i++) {
				if(i) pr(" ");
				pr("%d", trocas[i]+1);
			}pr("\n");
		}
	}
 	return 0;
}
