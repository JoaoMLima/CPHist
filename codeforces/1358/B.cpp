#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 200010

typedef long long ll;
typedef pair<int, int> ii;

int n, t, a, b, c, m;
int li[MAX];
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i < n; i++){
			sc("%d", li+i);
		}
		int r = 1;
		sort(li, li+n);
		for(int i = 0; i < n; i++){
			if (li[i] <= i+1) {
				r = i+2;
			}
		}
		pr("%d\n", r);

	}
 	return 0;
}
