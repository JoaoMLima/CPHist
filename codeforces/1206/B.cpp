#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
int n;
long long a;
int main(){
	int mul = 1;
	int total0 = 0;
	long long custo = 0;
	sc("%d", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", &a);
		if(a == 0LL) {custo++; total0++;}
		else if(abs(a-1) < abs(a+1)){
			custo += abs(a-1);
		} else {
			custo += abs(a+1);
			mul = -mul;
		}
	}
	if(mul == 1 || total0) {
		pr("%lld\n", custo);
	} else {
		pr("%lld\n", custo+2LL);
	}
 	return 0;
}
