#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
int li[200010];

int n, t, a, b, c;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	sc("%d\n", &t);
	while(t--) {
		vector<char> s;
		char ch = getchar();
		while(ch != '\n') {
			s.pb(ch);
			ch = getchar();
		}
		vector<int> pos;
		for(int i = 0; i < (int)s.size();) {
			if ((i+4) < (int)s.size() && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o' && s[i+3] == 'n' && s[i+4] == 'e') {
				pos.pb(i+3);
				i = i+5;
			} else if ((i+2) < (int)s.size() && s[i] == 'o' && s[i+1] == 'n' && s[i+2] == 'e') {
				pos.pb(i+2);
				i = i+3;
			} else if ((i+2) < (int)s.size() && s[i] == 't' && s[i+1] == 'w' && s[i+2] == 'o') {
				pos.pb(i+2);
				i = i+3;
			} else {
				i = i+1;
			}
		}
		pr("%d\n", (int)pos.size());
		for(int i = 0; i < (int)pos.size(); i++) {
			if(i) pr(" ");
			pr("%d", pos[i]);
		}pr("\n");
	}
 	return 0;
}
