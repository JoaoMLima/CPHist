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

map<string, set<string>> ma;

vector<int> alarms;
vector<int> used;
int main(){
	int n, m, k, a;
	sc("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		alarms.pb(a);
	}
	sort(alarms.begin(), alarms.end());
	int i = 0, j = 0, qtd = 0;
	int r = 0;
	while(i < n && j < n) {
		while(j < n && alarms[j] < alarms[i]+m) {
			if (qtd == k-1) {
				used.pb(0);
			} else {
				used.pb(1);
				qtd++;
			}
			j++;
		}
		if (used[i]) qtd--;
		i++;
	}
	qtd = 0;
	for(int x : used) {
		if (!x) qtd++;
	}
	pr("%d\n", qtd);
	
	
 	return 0;
}
