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

int bit[100010];
int qntrec[100010];
int query(int i) {
	i = 100010-i;
	int s = 0;
	for(; i; i-= i&(-i)) s += bit[i];
	return s;
}

void update(int i) {
	i = 100010-i;
	for(;i < 100010; i += i&(-i)) bit[i]++;
}

vector<int> v;

int n, a;
int main(){
	map<int, int> m;
	sc("%d", &n);
	int maxi = 0;
	int cntrec = 0;
	for(int i = 1; i <= n; i++) {
		sc("%d", &a);
		int inv = query(a);
		m[a] = 0;
		if (inv == 1) {m[maxi]++;}
		if (a > maxi) {cntrec++;m[a]--;}
		maxi = max(maxi, a);
		update(a);
	}
	int maxicnt = -1;
	int r = 1;

	for(ii e : m) {
		if (e.second > maxicnt) {
			maxicnt = e.second;
			r = e.first;
		}
	}
	pr("%d\n", r);

 	return 0;
}
