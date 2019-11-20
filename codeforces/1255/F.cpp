#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int medi(int l, int r) {
	return (r+l)/2;
}

int main(){
	int n;
	ll a;
	cin >> n;
	int bst = 2;
	for(int i = 3; i <= n; i++) {
		cout << "2 1 " << bst << " " << i << endl;
		cin >> a;
		if (a < 0) bst = i;
	}
	vector<pair<ll, int> > v;
	for(int i = 2; i <= n; i++) {
		if (i != bst) {
			cout << "1 1 " << bst << " " << i << endl;
			cin >> a;
			v.pb({a, i});
		}
	}
	sort(v.begin(), v.end());
	int longest = v[v.size()-1].second;
	stack<int> neg;
	queue<int> pos;
	for(int i = v.size()-2; i >= 0; i--) {
		cout << "2 1 " << longest << " " << v[i].second << endl;
		cin >> a;
		if (a > 0) pos.push(v[i].second);
		else neg.push(v[i].second);
	}
	cout << "0 1 " << bst;
	while(!neg.empty()) {
		cout << " " << neg.top();
		neg.pop();
	}
	cout << " " << longest;
	while(!pos.empty()) {
		cout << " " << pos.front();
		pos.pop();
	}
	cout << endl;


 	return 0;
}
