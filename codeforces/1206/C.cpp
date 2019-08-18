#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
int n;
int main(){
	sc("%d", &n);
	if(n % 2 == 0) {
		pr("NO\n");return 0;
	}
	pr("YES\n");
	if(n == 1) {pr("1 2\n"); return 0;}
	vector<int> seq1;
	vector<int> seq2;
	seq1.pb(1);
	seq2.pb(2);
	seq1.pb(2*n);
	seq2.pb(2*n - 1);
	bool ordem = false;
	for(int i = 3; i < 2*n-1; i+=2) {
		if(!ordem) {seq1.pb(i); seq2.pb(i+1); ordem = !ordem;}
		else {seq2.pb(i); seq1.pb(i+1); ordem = !ordem;}
	}
	for(int a : seq1) {
		pr("%d ", a);
	}
	for(int a : seq2) {
		pr("%d ", a);
	}
	pr("\n");
 	return 0;
}
