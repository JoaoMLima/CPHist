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
int acum[1000010];
int main(){
	int n, m, a; ll k;
	sc("%d\n", &n);
	int tam = 0;
	int acum = 0;
	int r = 0;
	for(int i = 1; i <= n; i++) {
		int ant = acum;
		if (getchar() == '(') acum++;
		else acum--;
		tam++;
		
		if (acum == 0) {
			if (ant == -1) {
				r += tam;
			}
			tam = 0;
		}
	}
	if (acum != 0) pr("-1\n");
	else pr("%d\n", r);
 	return 0;
}
