#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MAX 200010

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int n;
int bit[MAX];
int li[MAX];

void update(int i, int v) {
	i++;
	for(; i < MAX; i += (i&(-i))) bit[i] = max(bit[i], v);
}

int query(int i) {
	i++;
	int r = 0;
	for(; i; i -= (i&(-i))) r = max(r, bit[i]);
	return r;
}

int lis() {
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		int que = query(li[i]);
		maxi = max(maxi, que+1);
		update(li[i], que+1);
	}
	return maxi;
}

int main(){
    int k1, k2, k3, a;
	sc("%d %d %d", &k1, &k2, &k3);
	n = k1+k2+k3;
	for(int i = 0; i < k1+k2+k3; i++) {
		sc("%d", li+i);
	}
	sort(li, li+k1);
	sort(li+k1, li+k1+k2);
	sort(li+k1+k2, li+n);
	pr("%d\n", n-lis());

 	return 0;
}
