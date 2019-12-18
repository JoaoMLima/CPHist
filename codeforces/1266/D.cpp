#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 200020

typedef long long ll;
typedef pair<int, int> ii;
struct trp{
	ll f, s, t;
};

int n, m;
ll a, b, c;
ll  in[100010];
ll out[100010];

int main(){
	
	sc("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		sc("%lld %lld %lld", &a, &b, &c);
		in[b]+=c;
		out[a]+=c;
	}
	
	int rst = 0;
	for(int i = 1; i <= n; i++) {
		if(in[i] && out[i]) {
			ll x = min(in[i], out[i]);
			in[i] -= x;
			out[i] -= x;
		}
	}
	
	vector<trp> rsp;
	int i = 1, j = 1;
	while(i <= n && j <= n) {
		while(in[i]) {
			//cout << "i" << endl;
			while(!out[j]) {
				//cout << "j" << endl;
				j++;
			}
			ll x = min(in[i], out[j]);
			in[i]-=x;
			out[j]-=x;
			rsp.pb({j, i, x});
		}
		i++;
	}
	
	pr("%d\n", (int)rsp.size());
	for(int k = 0; k < (int)rsp.size(); k++) {
		pr("%lld %lld %lld\n", rsp[k].f, rsp[k].s, rsp[k].t);
	}

 	return 0;
}
