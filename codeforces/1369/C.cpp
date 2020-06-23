#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100010

typedef long long ll;
typedef pair<int, int> ii;

int n, t, k; ll a, b, c;
int li[200007];
int pesos[200007];
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d\n", &n, &k);
		int qtd1 = 0;
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
		}
		for(int i = 0; i < k; i++) {
			sc("%d", pesos+i);
			if (pesos[i] == 1) qtd1++;
		}
		ll sum = 0LL;
		sort(li, li+n);
		sort(pesos, pesos+k, greater<int>());
		for(int i = 0; i < k; i++) {
			if (pesos[i] == 1) {k = i; break;}
		}
		int i = 0, j = 0;
		while(i < n && j < k) {
			sum += li[i];
			for(int x = 0; x < pesos[j]-1; x++) {
				i++;
			}j++;
		}
		while(k--) {
			sum += li[i];
			i++;
		}
		while(qtd1--) {
			sum += li[i]+li[i];
			i++;
		}
		pr("%lld\n", sum);
	}
 	return 0;
}
