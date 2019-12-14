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
	sc("%d", &t);
	set<int> s;
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++) {
			sc("%d", &a);
			s.insert(-a);
		}
		int r = 0;
		while(!s.empty()) {
			int l = -(*(s.begin()));
			if (l & 1) {s.erase(-l);}
			else {
				s.erase(-l);
				s.insert(-(l>>1));
				r++;
			}
		}
		pr("%d\n", r);
	}
 	return 0;
}
