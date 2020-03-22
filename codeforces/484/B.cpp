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

int ult[1000001];
int tem[1000001];
int passou[2000001];


int ultimo(int x) {
	if (x > 1000000) return ult[1000000];
	return ult[x-1];
}

int main(){
	int n, a;
	vector<int> v;
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		v.pb(a);
		tem[a] = 1;
	}

	int atual = 0;
	for(int i = 1; i <= 1000000; i++) {
		if (tem[i]) atual = i;
		ult[i] = atual;
	}
	int maxi = 0;

	sort(v.begin(), v.end(), greater<int>());

	for(int x : v) {
		if (passou[x]) continue;
		for(int i = x; i <= 2000000; i += x) {
			if (ultimo(i) >= x) maxi = max(maxi, ultimo(i)%x);
			passou[i] = 1;
		}
	}
	pr("%d\n", maxi);
	
 	return 0;
}
