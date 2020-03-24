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
	int hv, av, cv, hm, am;
	sc("%d %d %d", &hv, &av, &cv);
	sc("%d %d", &hm, &am);
	int r = hm/av + (hm % av ? 1 : 0);
	int h = hm/av + (hm % av ? 1 : 0);
	for(int i = 0; i <= 1000000; i++) {
		if (cv*i + hv > am*(i+r-1)) {
			h = i;
			break;
		}
	}
	pr("%d\n", r+h);
	for(int i = 0;i < h; i++) {
		pr("HEAL\n");
	}
	for(int i = 0; i < r; i++) {
		pr("STRIKE\n");
	}
 	return 0;
}
