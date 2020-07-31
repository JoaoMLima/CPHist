#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int qtl[MAX][2];
int qtr[MAX][2];

int n, t;
int main(){
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		for(int i = 0; i <= sz(s)+1; i++) {
			qtl[i][0] = 0;
			qtl[i][1] = 0;
			qtr[i][0] = 0;
			qtr[i][1] = 0;
		}
		for(int i = 1; i <= sz(s); i++) {
			if (s[i-1] == '0') {qtl[i][0]++;qtr[i][0]++;}
			else {qtl[i][1]++;qtr[i][1]++;}
		}
		for(int i = 1; i <= sz(s); i++) {
			qtl[i][0] += qtl[i-1][0];
			qtl[i][1] += qtl[i-1][1];
		}
		for(int i = sz(s); i >= 1; i--) {
			qtr[i][0] += qtr[i+1][0];
			qtr[i][1] += qtr[i+1][1];
		}
		int zero = 1;
		int mini = sz(s);
		mini = min(mini, qtr[1][0]);
		mini = min(mini, qtr[1][1]);
		for(int i = 1; i < sz(s); i++) {
			if (s[i-1] == '0' && s[i] == '1') {
				zero = 0;
				mini = min(mini, qtl[i-1][1]+qtr[i+2][0]);
			}
			if (s[i-1] == '1' && s[i] == '0') {
				zero = 0;
				mini = min(mini, qtl[i-1][0]+qtr[i+2][1]);
			}
		}
		if (zero) pr("0\n");
		else pr("%d\n", mini);
	}
 	return 0;
}
