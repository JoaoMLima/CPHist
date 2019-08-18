#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
int n, a;
int main(){
	sc("%d", &n);
	int ma = -1;
	int mb = -1;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		ma = max(ma, a);
	}
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		mb = max(mb, a);
	}
	pr("%d %d\n", ma, mb);

 	return 0;
}
