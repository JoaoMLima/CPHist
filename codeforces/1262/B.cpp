#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, t;
int li[100010];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		set<int> s;
		int ant = 0;
		for(int i = 1; i <= n; i++) {
			s.insert(i);
		}
		int ok = 1;
		for(int i = 1; i <= n; i++) {
			sc("%d", &a);
			if (!ok) continue;
			if (a != ant) {
				ant = a;
				s.erase(a);
				li[i] = a;
			} else {
				if (*(s.begin()) > ant) {
					ok = 0;continue;
				} else {
					li[i] = *s.begin();
					s.erase(*s.begin());
				}
			}
		}
		if (ok) {
			for(int i = 1; i <= n; i++) {
				if(i != 1) pr(" ");
				pr("%d", li[i]);
			}pr("\n");
		}  else {
			pr("-1\n");
		}
	}
	
	
 	return 0;
}
