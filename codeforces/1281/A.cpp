#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c;
int main(){
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		if (s[s.length()-1] == 'o') {
			cout << "FILIPINO\n";
		} else if (s[s.length()-1] == 'u') {
			cout << "JAPANESE\n";
		} else {
			cout << "KOREAN\n";
		}
	}
 	return 0;
}
