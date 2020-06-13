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

int n, t, a, b, c;
int li[100007];
int mb[100007];
int main(){
	sc("%d", &n);
	int ok = 1;
	for(int i = 1; i <= n; i++) {
		sc("%d", li+i);
		if (li[i] > i) ok = 0;
		mb[i] = -1;
	}
	if (!ok){pr("-1\n");return 0;}
	set<int> s;
	for(int i = 0; i < li[n]; i++) {
		s.insert(i);
	}
	for(int i = n; i >= 1; i--) {
		if (s.count(li[i])) {
			mb[i+1] = li[i];
			//pr("mb: %d %d\n", i+1, li[i]);
			s.erase(li[i]);
		}
	}
	for(int i = 1; i <= n; i++) {
		if (i > 1) pr(" ");
		if (mb[i] != -1) {
			pr("%d", mb[i]);
		} else{
			if (!s.empty()) {
				int x = *(s.begin());
				s.erase(x);
				pr("%d", x);
			} else {
				pr("%d", li[n]+1);
			}
		}
	}pr("\n");
	
 	return 0;
}
