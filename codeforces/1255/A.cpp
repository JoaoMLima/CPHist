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


int main(){
    int a, b, t;
	sc("%d", &t);
	while(t--) {
		sc("%d %d", &a, &b);
		int re = 0;
		int dif = abs(a-b);
		re += dif / 5;
		dif -= (dif/5)*5;
		re += dif / 2;
		dif -= (dif/2)*2;
		re += dif;

		pr("%d\n", re);
	}
	

	
 	return 0;
}
