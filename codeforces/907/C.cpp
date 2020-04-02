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

int n;

int main(){
	set<char> podeser;
	for(char i = 'a'; i <= 'z'; i++) {
		podeser.insert(i);
	}
	cin >> n;
	int ok = 0;
	int r = 0;
	for(int i = 0; i < n; i++) {
		char ch;
		string s;
		cin >> ch >> s;
		//cout <<  "'" << ch << "'" << " '" << s << "'" << endl;
		if (ch == '!') {
			if(ok) r++; 
			set<char> naopode;
			for(char j = 'a'; j <= 'z'; j++) {
				naopode.insert(j);
			}
			for(char c : s) {
				naopode.erase(c);
			}
			for (char c : naopode) {
				podeser.erase(c);
			}
			
		} else if (ch == '.') {
			for(char c : s) {
				podeser.erase(c);
			}
		} else if (i != n-1) {
			podeser.erase(s[0]);
			if(ok) r++; 
		}
		/*
		for(char c : podeser) {
			cout <<  "'" << c << "' ";
		}cout << endl;*/
		if ((int)podeser.size() == 1) ok = 1;
	}
	pr("%d\n", r);
 	return 0;
}
