#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


typedef long long ll;
typedef pair<int, int> ii;

int n;
int dpt[100010];
int li[100010];

int main(){
	sc("%d\n", &n);
	for(int i = 1; i <= n; i++) {
		sc("%d", li+i);
	}
	int r = 0;
	for(int mx = -30; mx <= 30; mx++) {
		int maxi = INT_MIN;
		for(int i = 1; i <= n; i++) {
			if (li[i] <= mx) {
				dpt[i] = max(dpt[i-1]+li[i], li[i]);
				maxi = max(maxi, li[i]);
			} else {
				dpt[i] = 0;
				maxi = INT_MIN;
			}
			if (maxi != INT_MIN) r = max(r, dpt[i]-maxi);
		}
	}
	pr("%d\n", r);
	
 	return 0;
}
