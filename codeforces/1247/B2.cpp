#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 2010
#define MOD 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;
int li[200010];
map<int, int> m;
int main(){
	int n, t, k, d;
	sc("%d", &t);
	while(t--) {
		m.clear();
		sc("%d %d %d", &n, &k, &d);
		m[0] = 1;
		int r = 1000000;
		for(int i = 1; i <= n; i++) {
			sc("%d", li+i);
			m[li[i]]++;
			if(i >= d) {
				m[li[i-d]]--;
				if(!m[li[i-d]]) m.erase(li[i-d]);
				r = min(r, (int)m.size());
			}
		}
		pr("%d\n", r);
	}
 	return 0;
}
