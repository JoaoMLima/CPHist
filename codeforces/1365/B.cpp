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

int n, t, a, b,m;
int li[510];
int main(){
	sc("%d", &t);
	while(t--) {
		vector<int> v0;
		vector<int> v1;

		sc("%d", &n);
		vector<int> r(n, 0);
		vector<int> c(m, 0);
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			if (a) v1.pb(li[i]);
			else v0.pb(li[i]);
		}
		int ok = 1;
		for(int i = 1; i < (int)v0.size(); i++) {
			if (v0[i] < v0[i-1]) ok = 0;
		}
		for(int i = 1; i < (int)v1.size(); i++) {
			if (v1[i] < v1[i-1]) ok = 0;
		}
		pr((ok || ((int)v0.size() > 0 && (int)v1.size() > 0)) ? "Yes\n": "No\n");
	}
 	return 0;
}
