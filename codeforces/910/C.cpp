#include <bits/stdc++.h>
#define sc scanf
#define pr printf
#define fi first
#define se second

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef long double ld;

map<int, int> m[6];
int fir[10];
int sel[10];
ll sum[10];

int main() {
	int n;
	sc("%d", &n);
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 6; j++) {
			m[j][i] = 0;
		}
	}
	string s[n];
	set<char> qt[6];
	for(int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for(int j = 1; j <= tmp.length(); j++) {
			m[j-1][(int)(tmp[tmp.length()-j]-'a')]++;
			if(j == tmp.length()) fir[(int)(tmp[tmp.length()-j]-'a')] = 1;
		}
	}
	/*
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 6; j++) {
			cout << "{" << i <<  ", " << j << "}:" << m[j][i] << endl;
		}
	}*/
	for(int i = 0; i < 10; i++) {
		ll pot = 1;
		for(int j = 0; j < 6; j++) {
			sum[i] += m[j][i]*pot;
			pot *= 10;
		}
		//cout << i << ": " << sum[i] << endl;
	}
	ll res = 0;
	for(int i = 0; i < 10; i++) {
		int bst = -1; ll men = 0;
		for(int j = 0; j < 10; j++) {
			if(!sel[j] && (i != 0 || !fir[j]) && men < sum[j]) {
				bst = j;
				men = sum[j];
			}
		}
		if(bst != -1) sel[bst] = 1;
		//cout << bst << endl;
		res += sum[bst]*i;
	}
	pr("%lld\n", res);
	return 0;
}
