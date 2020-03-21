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


ll f(ll a, ll b) {
	if (a == 1LL) return b-1LL;
	return f(b%a, a)+b/a;
}

int main(){
	ll a, b;
	cin >> a >> b;
	cout << f(a, b)+1LL << endl;
	
 	return 0;
}
