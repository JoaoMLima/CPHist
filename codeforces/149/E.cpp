#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 102007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

vector<char> original;
vector<char> tmp;
char str[MAX];
int p[MAX];
int s[MAX];


int main(){
	int n, a, b;
	char ch = getchar();
	while(ch != '\n') {
		original.pb(ch);
		ch = getchar();
	}
	int r = 0;
	sc("%d\n", &n);
	for(int z = 0; z < n; z++) {
		tmp.clear();
		ch = getchar();
		while(ch != '\n') {
			tmp.pb(ch);
			ch = getchar();
		}
		if (sz(tmp) == 1) continue;
		for(int i = 0; i < 1001; i++) {
			if (i < sz(tmp)) str[i] = tmp[i];
			else str[i] = '$';
		}
		
		for(int i = 1001; i < 101002; i++) {
			if (i-1001 < sz(original)) str[i] = original[i-1001];
			else str[i] = '$';
		}
		for(int i = 0; i < 1000; i++) {
			if (i < sz(tmp)) str[102001-i] = tmp[sz(tmp)-1-i];
			else str[102001-i] = '$';
		}
		
		p[0] = 0;
		for(int i = 1; i < 101002; i++) {
			int j = p[i-1];
			//pr("i: %d j: %d\n", i, j);
			while(j > 0 && str[j] != str[i]) {
				//pr("i: %d j: %d\n", i, j);
				j = p[j-1];
			}
			if (str[j] == str[i]) j++;
			//pr("i: %d j: %d\n", i, j);
			p[i] = j;
		}
		
		s[102001] = 0;
		for(int i = 102000; i >= 1001; i--) {
			int j = s[i+1];
			while(j > 0 && str[102001-j] != str[i]) {
				j = s[102001-j+1];
			}
			if (str[102001-j] == str[i]) j++;
			s[i] = j;
		}

		for(int i = 1002; i < 1001+sz(original); i++) {
			p[i] = max(p[i], p[i-1]);
		}

		for(int i = 1001+sz(original)-2; i >= 1001; i--) {
			s[i] = max(s[i], s[i+1]);
		}
	/*
		for(int i = 1001; i < 1001+sz(original); i++) {
			cout << p[i] << " ";
		}cout << endl;

		for(int i = 1001; i < 1001+sz(original); i++) {
			cout << s[i] << " ";
		}cout << endl;
*/
		int ok = 0;
		for(int i = 1001; i < 1001+sz(original); i++) {
			int x = p[i];
			if (i-1001+1 < 1001+sz(original)) {
				x += s[i+1];
				if (x >= sz(tmp)) {
					ok = 1;
					break;
				}
			}
		}
		if (ok) r++;
	}

	pr("%d\n", r);
	
 	return 0;
}