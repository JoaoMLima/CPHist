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
 
set<int> squares;
vector<int> distssquares;
vector<int> distsnot;

int n, a, b, c;
int main(){
	sc("%d", &n);
	ll r = 0;
	int last = 0;
	for(int i = 0; i <= 31623; i++) {
		squares.insert(i*i);
		last = i;
	}
	//pr("%d\n", last);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		if (squares.count(a)) {
			if(!a) distssquares.pb(2);
			else distssquares.pb(1);
		} else {
			int mini = 1000000000;
			set<int>::iterator it = squares.lower_bound(a);
			mini = min(mini, abs((*it)-a));
			it = prev(it);
			mini = min(mini, abs((*it)-a));
			distsnot.pb(mini);
		}
	}
	sort(distsnot.begin(), distsnot.end());
	sort(distssquares.begin(), distssquares.end());
	if ((int)distssquares.size() < n/2) {
		for(int i = 0; i < (n/2 - (int)distssquares.size()); i++) {
			r += distsnot[i];
		}
	} else {
		for(int i = 0; i < (n/2 - (int)distsnot.size()); i++) {
			r += distssquares[i];
		}
	}
	pr("%lld\n", r);
 	return 0;
}