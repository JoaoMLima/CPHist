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
int li[110];
int li2[110];
int main(){
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%d", li+i);
	}
	for(int i = 0; i < n; i++) {
		sc("%d", li2+i);
	}
	int qtd1 = 0;
	int qtd2 = 0;
	for(int i = 0; i < n; i++) {
		if (li[i] && !li2[i]) qtd1++;
		if (!li[i] && li2[i]) qtd2++;
	}
	if (!qtd1) { pr("-1\n"); return 0;}
	for(int i = 1; i < 1000; i++) {
		if (qtd1*i > qtd2) {
			pr("%d\n", i);
			return 0;
		}
	}
 	return 0;
}
