#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
ll a, b, c;
int main(){
	int t, n;
	sc("%d", &t);
	while(t--) {
		string s;
		cin >> n >> s;
		vector<ii> v;
		for(int i = 0; i < n-1;) {
			int maxi = i;
			for(int j = i+1; j < n-1; j++) {
				if (s[j] != s[i]) break;
				maxi = j;
			}
			if (s[i] == '<') {
				v.pb({maxi-i+1, 0});
			} else {
				v.pb({maxi-i+1, 1});
			}
			i = maxi+1;
		}
		vector<int> v1;
		vector<int> v2;
		int maxi = n;
		//v[0].first++;
		for(int i = 0; i < v.size(); i++) {
			ii step = v[i];
			//if (step.first == n-1) break;
			//
			if (!step.second) step.first++;
			else if (i && step.second) step.first--;
			if (step.second) {
				for(int i = 0; i < step.first; i++) {
					v1.pb(maxi--);
				}
			} else {
				int tmp = maxi-step.first+1;
				for(int i = 0; i < step.first; i++) {
					v1.pb(tmp+i);
				}
				maxi = tmp-1;
			}
		}
		int mini = 1;
		for(int i = 0; i < v.size(); i++) {
			ii step = v[i];
			//if (step.first == n-1) break;
			//cout << "step: " <<  step.first << endl;
			if (step.second) step.first++;
			else if (i && !step.second) step.first--;
			if (step.second) {
				int tmp = mini+step.first-1;
				for(int i = 0; i < step.first; i++) {
					v2.pb(tmp-i);
				}
				mini = tmp+1;
				
			} else {
				for(int i = 0; i < step.first; i++) {
					v2.pb(mini++);
				}
			}
		}
		if (v1.size() < n) {
			v1.pb(1);
		}
		if (v2.size() < n) {
			v2.pb(n);
		}
		/*
		if (v[0].first == n-1) {
			if (v[0].second) {
				for(int i = n; i > 0; i--) {
					v1.pb(i);
					v2.pb(i);
				}
			} else {
				for(int i = 1; i<= n; i++) {
					v1.pb(i);
					v2.pb(i);
				}
			}
		} else {
			if ()
		}*/
		for(int x : v1) {
			if (x != v1[0])cout << " ";
			cout << x;
		}cout <<"\n";
		for(int x : v2) {
			if (x != v2[0])cout << " ";
			cout << x;
		}cout <<"\n";
	}
 	return 0;
}
