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

int n, m, a, b;
int p[200010];
int main(){
	vector<int> v;

	sc("%d", &n);
	for(int i = 0; i <= n; i++) {
		sc("%d", &a);
		v.pb(a);
	}
	int ok = 0;
	for(int i = 1; i <= n; i++) {
		if (v[i] > 1 && v[i-1] > 1) ok = 1;
	}
	if (!ok) {
		pr("perfect\n");
		return 0;
	}
	pr("ambiguous\n");
	int x = 0;
	int lasth1 = 0, lasth2 = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= v[i]; j++) {
			if (j == 1) {
				p[j+x]=lasth1;
			} else {
				p[j+x]=lasth2;
			}
		}
		if (v[i] == 1) {
			lasth1 = x+1;
			lasth2 = x+1;
		} else {
			lasth1 = x+1;
			lasth2 = x+2;
		}
		x += v[i];
	}
	
	for(int i = 1; i <= x; i++) {
		if(i > 1) pr(" ");
		pr("%d", p[i]);
	}pr("\n");

	x = 0;
	lasth1 = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 1; j <= v[i]; j++) {
			p[j+x]=lasth1;
		}
		lasth1 = x+1;
		x += v[i];
	}

	for(int i = 1; i <= x; i++) {
		if(i > 1) pr(" ");
		pr("%d", p[i]);
	}pr("\n");
	
 	return 0;
}
