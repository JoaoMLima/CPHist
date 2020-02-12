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
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int f1 = -1;
		int qt0 = 0;
		int qt0u1 = 0;
		for (int j = 0; j < (int)s.length(); j++) {
			if (s[j] == '1') {
				if (f1 >= 0) {
					qt0u1 = qt0;
				} else {
					f1 = j;
				}
			} else {
				if (f1 >= 0) {
					qt0++;
				}
			}
		}
		pr("%d\n", qt0u1);
	}
 	return 0;
}
