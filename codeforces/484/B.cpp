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
int pre[2000010];
int nex[2000010];

void erase(int x) {
	nex[pre[x]] = nex[x];
	pre[nex[x]] = pre[x];
}
int ultimo(int x) {
	if (x > 1000000) return ult[1000000];
	return ult[x-1];
}

int main(){
	int n, a;
	vector<int> v;
	sc("%d", &n);
	for(int i = 0; i <= 2000001; i++) {
		pre[i] = i-1;
		nex[i] = i+1;
	}
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		v.pb(a);
		tem[a] = 1;
	}

	sort(v.begin(), v.end(), greater<int>());
	int atual = 0;
	for(int i = 1; i <= 1000000; i++) {
		if (tem[i]) atual = i;
		ult[i] = atual;
	}
	int maxi = 0;

	for(int x : v) {
		if (pre[nex[x]] != x) continue;
		//cout << x << endl;
		int i = nex[0];
		while(i != 2000001) {
			//cout << "i: " << i << endl;
			if ((i*1LL*x) > 2000000LL) break;
			if (ultimo(i*x) >= x) maxi = max(maxi, ultimo(i*x)%x);
			erase(i*x);
			i = nex[i];
		}
	}
	pr("%d\n", maxi);
	
 	return 0;
}
