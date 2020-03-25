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
 
map<string, set<string>> ma;
 
int issuffix(string &s1, string &s2) {//returns 0 -> no 1 -> s1 is suffix 2 -> s2 is suffix
	int r = (s1.length() < s2.length()) ? 1 : 2;
	int l = min(s1.length(), s2.length());
	int ok = 1;
	for(int i = 1; i <= l; i++) {
		if (s1[s1.length() - i] != s2[s2.length() - i]) ok = 0;
	}
	return r*ok;
}
 
int n, a, b, c;
int main(){
	sc("%d", &n);
	while(n--) {
		string s;
		cin >> s >> a;
		for(int i = 0; i < a; i++) {
			string s1;
			cin >> s1;
			int insere = 1;
			for(string tmp : ma[s]) {
				int suf = issuffix(s1, tmp);
				if (suf == 1) {
					insere = 0;break;
				} else if (suf == 2) {
					ma[s].erase(tmp);
					break;
				}
			}
			if (insere) ma[s].insert(s1);
		}
	}
	cout << (int)ma.size() << endl;
	for (pair<string, set<string> > ph : ma) {
		cout << ph.first << " " << (int)ph.second.size();
		for(string s1 : ph.second) {
			cout << " " << s1;
		}cout << endl;
	}
 	return 0;
}