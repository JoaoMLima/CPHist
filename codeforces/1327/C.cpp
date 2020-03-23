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


int t, n, m, k, a, b;
vector<ii> chips;
vector<ii> local;

int main(){
	sc("%d %d %d", &n, &m , &k);
	vector<char> v;
	for(int i = 1; i < n; i++) {
		v.pb('D');
	}
	for(int i = 1; i < m; i++) {
		v.pb('L');
	}
	int j = 1;
	for(int i = 1; i <= n; i++) {
		if (j == 1) {
			for(; j < m; j++) {
				v.pb('R');
			}
		} else {
			for(; j > 1; j--) {
				v.pb('L');
			}
		}
		if (i != n) v.pb('U');
	}
	pr("%d\n", (int)v.size());
	for(char ch: v ) {
		putchar(ch);
	}pr("\n");


 	return 0;
}
