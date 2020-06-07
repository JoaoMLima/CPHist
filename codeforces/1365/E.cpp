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

int n; ll a, b,m;
ll li[510];
int main(){
	ll maxi = 0LL;
	sc("%d\n", &n);
	for(int i = 0; i < n; i++) {
		sc("%lld", &a);
		li[i] = a;
	}
	for(int i = 0; i < n; i++) {
		maxi = max(maxi, li[i]);
		for(int j = i+1; j < n; j++) {
			maxi = max(maxi, li[i] | li[j]);
			for(int k = j+1; k < n; k++) {
				maxi = max(maxi, li[i] | li[j] | li[k]);
			} 
		}
	}
	pr("%lld\n", maxi);

 	return 0;
}
