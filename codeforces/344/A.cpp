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
	string pre = "eae";
	string s;
	int gr = 0;
	for(int i = 0; i < n; i++) {
		cin >> s;
		if (s != pre)gr++;
		pre = s;
	}
	cout << gr << endl;
 	return 0;
}
