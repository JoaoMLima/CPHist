#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;

int n, m, k, a, b, c;
int ok[2000007];
int ca[100007];
int co[100007];
int vi[200007];
vector<ii> g[100007];

int main(){
	sc("%d %d", &n, &m);
	set<ii> s; // {ca-co, i}
	vector<int> resp;
	for(int i = 1; i <= n; i++) {
		sc("%d", co+i);
	}
	for(int i = 1; i <= m; i++) {
		sc("%d %d", &a, &b);
		g[a].pb({i, b});
		g[b].pb({i, a});
		ca[a]++;
		ca[b]++;
	}
	for(int i = 1; i <= n; i++) {
		s.insert({ca[i]-co[i], i});
	}
	int ok = 1;
	for(int i = 1; i <= n; i++) {
		ii f = *(s.begin());
		s.erase(f);
		if (f.fi > 0) {
			pr("DEAD\n");
			return 0;
		}
		for(ii x: g[f.se]) {
			if (!vi[x.se]) {
				resp.pb(x.fi);
				s.erase({ca[x.se]-co[x.se], x.se});
				ca[x.se]--;
				s.insert({ca[x.se]-co[x.se], x.se});
			}
		}
		vi[f.se] = 1;
	}
	pr("ALIVE\n");
	for(int i = (int)resp.size()-1; i >= 0; i--) {
		if (i != (int)resp.size()-1) pr(" ");
		pr("%d", resp[i]);
	}pr("\n");
 	return 0;
}
