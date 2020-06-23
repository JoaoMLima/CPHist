#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int n, t; ll a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d\n", &n);
		vector<char> s;
		vector<char> t;
		int f1 = -1;
		int l0 = -1;
		for(int i = 0; i < n; i++) {
			char ch = getchar();
			if (ch == '0') l0 = i;
			if (ch == '1' && f1 == -1) f1 = i;
			s.pb(ch);
		}getchar();
		if (l0 == -1 || f1 == -1 || l0 < f1) {
			t = s;
		} else {
			for(int i = 0; i < f1; i++) {
				t.pb(s[i]);
			}
			t.pb('0');
			for(int i = l0+1; i < n; i++) {
				t.pb(s[i]);
			}
		}
		for(int i = 0; i < (int)t.size(); i++) {
			putchar(t[i]);
		}pr("\n");
	}
 	return 0;
}
