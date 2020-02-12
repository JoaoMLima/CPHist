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

int n, a, b, c;
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		set<char> g[26];
		for(int i = 1; i < (int)s.length(); i++) {
			g[s[i]-'a'].insert(s[i-1]-'a');
			g[s[i-1]-'a'].insert(s[i]-'a');
		}
		vector<char> p0;
		vector<char> p1;
		vector<char> p2;
		set<char> usados;
		int ok = 1;
		for(char i = 0; i < 26; i++) {
			usados.insert(i);
			if (g[i].size() == 0) {
				p0.pb(i);
			} else if (g[i].size() == 1) {
				p1.pb(i);
			} else if (g[i].size() == 2) {
				p2.pb(i);
			} else {
				ok = 0;
			}
		}
		
		if (ok == 0) {
			pr("NO\n");
			continue;
		}
		vector<char> s2;

		for(char c : p0) {
			s2.pb(c);
			usados.erase(c);
		}
		for(char c : p1) {
			if (usados.count(c)) {
				usados.erase(c);
				s2.pb(c);
				char antc = c;
				c = *(g[c].begin());
				g[c].erase(antc);
				while (1) {
					usados.erase(c);
					s2.pb(c);
					if (g[c].size() > 0) {
						antc = c;
						c = *(g[c].begin());
						g[c].erase(antc);
					} else {
						break;
					}
				}
			}
		}
		if (usados.size() > 0) {
			pr("NO\n");
		} else {
			pr("YES\n");
			for(int i = 0; i < s2.size(); i++) {
				putchar(s2[i]+'a');
			}pr("\n");
		}
		
	}
 	return 0;
}
