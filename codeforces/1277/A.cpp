#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
	sc("%d", &n);
	int r = 0;
	for(int i = 1; i <= 9; i++) {
		int v = 0;
		for(int j = 1; j <= 9; j++) {
			v = 10*v+i;
			if(v <= n)r++;
		}
	}
	pr("%d\n", r);}
 	return 0;
}
