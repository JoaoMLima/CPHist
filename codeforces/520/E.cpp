#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 100010
#define mod 1000000007LL

typedef long long ll;
typedef pair<int, int> ii;
int inv[MAX];
int fact[MAX];
ll modPow(ll b, ll e) {
	//cout << b << " " << e << endl;
	if (!e) return 1LL;
	if (e&1) return b * modPow(b, e-1) % mod;
	ll r = modPow(b, e>>1);
	return r*r%mod;
}
int bit[10][MAX];
int query(int d, int i) {
	i = MAX-i-1;
	int s = 0;
	while(i) {
		s += bit[d][i];
		i -= i&(-i);
	} 
	return s;
}
void update(int d, int i) {
	i = MAX-i-1;
	while(i < MAX) {
		bit[d][i]++;
		i += i&(-i); 
	}
}
ll comb(ll x, ll y) {
	//cout << x << " " << y << endl;
	if(x < 0 || y < 0 || x < y) return 0;
	if(y == 0 || x == y) return 1;
	return 1LL*fact[x]*inv[y]%mod*inv[x-y]%mod;
}
int li[MAX];
int main(){
	int n, k; char a;
	ll resp = 0LL;
	fact[1] = 1; inv[1] = 1;
	for(int i = 2; i < MAX; i++) {
		//cout << i << endl;
		fact[i] = fact[i-1]*1LL*i % mod;
		//cout << fact[i] << endl;
		inv[i] = modPow(fact[i], mod-2);
	}
	
	sc("%d %d\n", &n, &k);

	for(int i = 0; i < n; i++) {
		sc("%c", &a);
		li[i] = a-'0';
	}
	for(int i = 0; i < n; i++) {
		update(li[i], n-1-i);
	}
	for(int i = 0; i < 10; i++) {
		//cout << "d: " << i << endl;
		ll modulo = i;
		for(int j = 1; j < n; j++) {
			ll temp = modulo*query(i, j)%mod;
			ll c = comb(n-1-j, k-1);
			resp = (resp + temp*c)%mod;
			modulo = (10*modulo) % mod;
			//cout << "j: " << j << " resp: " << resp << endl;
			//cout << "query: " << query(i, j) << " comb: " << c << endl;
		}
	}

	for(int i = 0; i < 10; i++) {
		ll modulo = i;
		for(int j = n-1; j >= 0; j--) {
			if(li[j] == i) {
				resp = (resp + modulo*comb(j, k))%mod;
			}
			modulo = (10*modulo) % mod;
		}
	}
	pr("%lld\n", resp);
	//sc("%d", &);
	//sc("%d %d", &, &);
	//sc("%d %d %d", &, &, &);
	//sc("%d %d %d %d", &, &, &, &);
	//for (int i = 0; i < ; i++)*/
 	return 0;
}
