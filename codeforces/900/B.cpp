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

int n, a, b, c;
int main(){
	sc("%d %d %d", &a, &b, &c);
	set<ii> d;
	int i = 1;
	while(1) {
		ii dg = {(a*10)/b, (a*10)%b};
		if(d.count(dg)) {
			pr("-1\n"); return 0;
		}
		if ((a*10)/b == c) {
			pr("%d\n", i);return 0;
		}
		d.insert(dg);
		a = (a*10)%b;
		i++;
	}

 	return 0;
}
