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
int ok[120];
int main(){
	sc("%d\n", &n);
	vector<char> s;
	for(int i = 0; i < n; i++) {
		s.pb(getchar());
	}
	int total = 0;
	for(char c = 'z'; c >= 'a'; c--) {
		int fst = -1;
		for(int i = 0; i < (int)s.size(); i++) {
			ok[i] = 1;
			if (s[i] == c && fst == -1) {
				fst = i;
			}
			if (s[i] != c && fst != -1) {
				if (s[i] == c-1 || (fst-1 >= 0 && s[fst-1] == c-1)) {
					total += i-fst;
					for(int j = fst; j < i; j++) {
						ok[j] = 0;
					}
				}
				fst = -1;
			}
		}
		if (fst != -1) {
			if (fst-1 >= 0 && s[fst-1] == c-1) {
				total += (int)s.size()-fst;
				for(int j = fst; j < (int)s.size(); j++) {
					ok[j] = 0;
				}
			}
		}
		vector<char> s2;
		for(int i = 0; i < (int)s.size(); i++) {
			if (ok[i]) {s2.pb(s[i]);}
		}
		s = s2;
	}
	pr("%d\n", total);
	
 	return 0;
}
