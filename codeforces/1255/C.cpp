#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
struct triple {
	int l, m, r;
	bool contains(int a) {return (l == a || m == a || r == a);}
};
vector<int> trp[100010];
triple li[100010];

int main(){
    int a, b, c, t, n, m;
	sc("%d", &n);
	vector<int> resp;
	for(int i = 0; i < n-2; i++) {
		sc("%d %d %d", &a, &b, &c);
		li[i] = {a, b, c};
		trp[a].pb(i);
		trp[b].pb(i);
		trp[c].pb(i);
	}
	int ponta = -1;
	int nextPonta = -1;
	for(int i = 1; i <= n; i++) {
		if (trp[i].size() == 1) {
			ponta = i;
			break;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		if (trp[i].size() == 2) {
			if (li[trp[i][0]].contains(ponta) || li[trp[i][1]].contains(ponta)) {
				nextPonta = i;
			}
		}
	}
	resp.pb(ponta);
	resp.pb(nextPonta);
	int ok = 1;
	while(ok) {
		int ult = resp[resp.size()-1];
		int pen = resp[resp.size()-2];
		int ant = (resp.size() > 2) ? resp[resp.size()-3] : -1;
		ok = 0;
		for(int i = 0; i < trp[ult].size(); i++) {
			if (li[trp[ult][i]].contains(ult) && li[trp[ult][i]].contains(pen) && !li[trp[ult][i]].contains(ant)) {
				set<int> s;
				s.insert(li[trp[ult][i]].l);
				s.insert(li[trp[ult][i]].m);
				s.insert(li[trp[ult][i]].r);
				s.erase(ult);
				s.erase(pen);
				resp.pb(*s.begin());
				ok = 1;
				break;
			}
		}
	}
	for(int i = 0; i < n; i++) {
		if (i) pr(" ");
		pr("%d", resp[i]);
	}pr("\n");
 	return 0;
}
