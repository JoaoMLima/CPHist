#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 200010

typedef long long ll;
typedef pair<int, int> ii;
int bit[MAX];
int li[MAX];
int resp[MAX];
struct que {int k, pos, index;};
vector<int> v;
vector<que> quer;
bool comp(int i, int j) {
	if (li[i] != li[j]) return li[i] > li[j];
	return i < j;
}
bool comp2(que i, que j) {
	return i.k < j.k;
}

void update(int i) {
	for(; i < MAX; i += (i&(-i))) {
		bit[i]++;
	}
}
int n, m, a, b, c;
int kesim(int k) {
	k--;
	int antk = 0;
	int antbits = 0;
	for(int i = 17; i >= 0; i--) {
		if (antbits + (1<<i) > n) {
			continue;
		}
		if (antk + bit[antbits + (1<<i)] <= k) {
			antk += bit[antbits + (1<<i)];
			antbits += (1<<i);
		}
	}
	return antbits+1;
}
int main(){
	sc("%d", &n);
	for(int i = 1;i <= n; i++) {
		sc("%d", li+i);
		v.pb(i);
	}
	sort(v.begin(), v.end(), comp);

	sc("%d", &m);
	for(int i = 1; i <= m; i++) {
		sc("%d %d", &a, &b);
		quer.pb({a, b, i});
	}
	sort(quer.begin(), quer.end(), comp2);
	int i = 0, j = 0;
	
	while(j < (int)quer.size()) {
		while(i < quer[j].k) {
			update(v[i++]);
		}
		resp[quer[j].index] = li[kesim(quer[j].pos)];
		j++;
	}
	for(int i = 1; i <= m; i++) {
		pr("%d\n", resp[i]);
	}
 	return 0;
}
