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

int main(){
	int t;
	cin >> t;
	while(t--) {
	string s;
	cin >> s;
	vector<char> s2;
	int ok = 1;
	for(int i = 0; i < s.length(); i++) {
		if (s[i] != '?') {
			s2.pb(s[i]);
		} else if (i == 0) {
			if(s[i+1] == 'a')s2.pb('b');
			else s2.pb('a');
		} else if (i == s.length()-1){
			if(s2[i-1] == 'a')s2.pb('b');
			else s2.pb('a');
		} else {
			int a = 0, b = 0, c = 0;
			if (s2[i-1] == 'a') a = 1;
			if (s2[i-1] == 'b') b = 1;
			if (s2[i-1] == 'c') c = 1;
			if (s[i+1] == 'a') a = 1;
			if (s[i+1] == 'b') b = 1;
			if (s[i+1] == 'c') c = 1;
			if (!a) s2.pb('a');
			else if (!b) s2.pb('b');
			else s2.pb('c');
		}
		if(s2[i] == s2[i-1]) ok = 0;
	}
	if(!ok) {
		pr("-1\n"); continue;
	}

	for(int i = 0; i < s2.size(); i++) {
		putchar(s2[i]);
	}putchar('\n');
	}
 	return 0;
}
