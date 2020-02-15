#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int vi[110];
string li[110];
map<string, int> qtd;
map<string, string> rev;
map<string, int> vis;
vector<string> ini;
vector<string> fin;
string maxp = "";
int main(){
	int n, m;
	sc("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		li[i] = tmp;
		qtd[tmp]++;
		string tmp2 = tmp;
		reverse(tmp2.begin(), tmp2.end());
		//cout << tmp2 << endl;
		rev[tmp] = tmp2;
	}
	for(int i = 0; i < n; i++) {
		string tmp = li[i], revtmp = rev[li[i]];
		if (!vis[tmp]) {
			if (tmp == revtmp) {
				int x = qtd[tmp];
				for(int i = 0; i < x/2; i++) {
					ini.pb(tmp);
					fin.pb(revtmp);
				}
				if (x%2 > 0 && tmp.length() > maxp.length()) {
					maxp = tmp;
				}
				vis[tmp] = 1;
			} else if (qtd[revtmp] > 0) {
				int x = min(qtd[tmp], qtd[revtmp]);
				for(int i = 0; i < x; i++) {
					ini.pb(tmp);
					fin.pb(revtmp);
				}
				vis[tmp] = 1;
				vis[revtmp] = 1;
			}
		}
	}
	int sz = 0;
	for(string s : ini) {
		sz += s.length();
	}
	sz += maxp.length();
	for(int i = fin.size()-1; i >= 0; i--) {
		sz += fin[i].length();
	}
	cout << sz << endl;
	for(string s : ini) {
		cout << s;
	}
	cout << maxp;
	for(int i = fin.size()-1; i >= 0; i--) {
		cout << fin[i];
	}cout << endl;
 	return 0;
}
