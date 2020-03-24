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
	vector<int> v;
	sc("%d", &n);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		m[a]++;
	}
	int maxi = 0;
	for(ii p : m) {
		maxi = max(maxi, p.second);
	}
	pr("%d\n", maxi);
 	return 0;
}
