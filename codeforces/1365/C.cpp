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
int li[200010];
int last[200010];
int qt[200010];
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	int k = 0;
	for(int i = 0; i < n; i++) {
		last[li[i]] = k+n;
		k++;
	}
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		int l = last[a]-i;
		if (l >= n) l -= n;
		qt[l]++;
	}
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		maxi = max(maxi, qt[i]);
	}
	pr("%d\n", maxi);
 	return 0;
}
