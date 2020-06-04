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

int n, t, a, b, c, k;
vector<string> v;
set<string> st;
int main(){
	sc("%d %d\n", &n, &k);
	for(int i = 0; i < n; i++) {
			string s;
		cin >> s;
		st.insert(s);
		v.pb(s);
	}
	int tot = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (i == j) continue;
			string s = "";
			for(int l = 0; l < k; l++) {
				if (v[i][l] == v[j][l]) {
					s += v[j][l];
				} else if (v[i][l] == 'S') {
					if (v[j][l] == 'E') s += 'T';
					else s += 'E';
				} else if (v[i][l] == 'E') {
					if (v[j][l] == 'S') s += 'T';
					else s += 'S';
				} else if (v[i][l] == 'T') {
					if (v[j][l] == 'S') s += 'E';
					else s += 'S';
				}
			}
			if (st.count(s)) {
				//cout << v[i] << " " << v[j] << endl;
				tot++;
			}
		}
	}
	pr("%d\n", tot/6);
 	return 0;
}
