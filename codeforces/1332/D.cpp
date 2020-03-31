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

int n, a, b, c, t, k;
int p[200010];
stack<ii> rollback;

void rollbacks() {
	while(!rollback.empty()) {
		ii f = rollback.top(); rollback.pop();
		p[f.fi] = f.se;
	}
}

int find(int a) {
	if (p[a] == a) return a;
	rollback.push({a, p[a]});
	return p[a] = find(p[a]);
}

void uni(int a, int b) {
	//cout << a << " " << b << " " << k << endl;
	a = find(a), b = find(b);
	if (rand() & 1) {
		rollback.push({a, p[a]});
		p[a] = b;
	} else {
		rollback.push({b, p[b]});
		p[b] = a;
	}
}

map<int, int> m[200010];
int sum[200010];
int maxi[200010];
int main(){
	sc("%d", &n);
	pr("3 2\n");
	pr("262143 %d\n", n);
	pr("131072 262143\n");
	pr("262143 131071\n");
 	return 0;
}
