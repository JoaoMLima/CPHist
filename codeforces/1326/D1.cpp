#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 1000007
#define HMAX 2

typedef long long ll;
typedef pair<int, int> ii;

int n, k, a, b, c;

ll modpow(ll a, ll b, ll m) {
	if (b == 0LL) return 1LL;
	if (b&1LL) return modpow(a, b-1LL, m)*a%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

ll inverse(ll a, ll b) {
	return modpow(a, b-2LL, b);
}

ll base[HMAX] = {317, 307};
ll mod[HMAX] = {104000717, 104000711};
ll power[HMAX][MAX], inv[HMAX][MAX];
ll h[HMAX][MAX];
ll invh[HMAX][MAX];
int sz = 0;

void init() {
	for(int k = 0; k < HMAX; k++) {
		power[k][0] = inv[k][0] = 1;
		power[k][1] = base[k];
		inv[k][1] = inverse(base[k],mod[k]);
		for(int i = 2; i < MAX; i++) {
			power[k][i] = (power[k][i-1]*power[k][1])%mod[k];
			inv[k][i] = (inv[k][i-1]*inv[k][1])% mod[k];
		}
	}
}

void build(string s) {
	sz = s.length();
	for(int k = 0; k < HMAX; k++) {
		h[k][0] = s[0];
		for(int i = 1; i < s.length(); i++) {
			h[k][i] = (h[k][i-1]+(s[i]*power[k][i])%mod[k])%mod[k];
			//cout << s[i]  << " " << h[k][i] << endl;
		}
		//cout << endl;
		invh[k][0] = s[s.length()-1];
		for(int i = 1; i < s.length(); i++) {
			invh[k][i] = (invh[k][i-1]+(s[sz-1-i]*power[k][i])%mod[k])%mod[k];
			//cout << s[sz-1-i]  << " " << invh[k][i] << endl;
		}
		//cout << endl;
	}
}

vector<ll> geth(int l, int r) {
	vector<ll> ret;
	for(int k = 0; k < HMAX; k++) {
		ll hr = h[k][r];
		ll hl = (l > 0) ? h[k][l-1] : 0;
		ll ans = ((hr+mod[k]-hl)*inv[k][l])%mod[k];
		ret.pb(ans);
	}
	return ret;
}
vector<ll> getInvh(int l, int r) {
	vector<ll> ret;
	for(int k = 0; k < HMAX; k++) {
		ll hr = invh[k][r];
		ll hl = (l > 0) ? invh[k][l-1] : 0;
		ll ans = ((hr+mod[k]-hl)*inv[k][l])%mod[k];
		ret.pb(ans);
	}
	return ret;
}
bool cmp(vector<ll> a, vector<ll> b) {
	for(int i = 0; i < a.size(); i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}

bool test(int left, int right) {
	if (left == right) {
		return cmp(geth(0, left-1), getInvh(0, left-1));
	} else {
		int mini = min(left, right);
		bool ok = true;
		if (mini != 0) {
			ok = (ok && cmp(geth(0, mini-1), getInvh(0, mini-1)));
		}
		int l, r;
		if (left > right) {
			l = right; r = left-1;
		} else {
			r = sz-1-left; l = sz-right;
		}
		//if (left == 2 && right == 0) cout << "aqui " << l << " " << r << " " << geth(l, r)[0] << " " << getInvh(sz-1-r, sz-1-l)[0] << " " << cmp(geth(l, r), getInvh(sz-1-r, sz-1-l)) << endl;
		//cout << "hashes: " << (int)geth(l, r)[0]] << " " << (int)getInvh(sz-1-r, sz-1-l)[0] << endl;
		ok = (ok && cmp(geth(l, r), getInvh(sz-1-r, sz-1-l)));
		return ok;
	}
}

int main(){
	init();
	cin >> n;
	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		build(s);
		/*
		for(int i = 0; i < sz; i++) {
			cout << h[0][i] << " ";
		}cout << endl;
		for(int i = 0; i < sz; i++) {
			cout << invh[0][i] << " ";
		}cout << endl;
		*/
		int l = 2, r = s.length();
		
		int pal = 0;
		for(int j = 1; j+j <= s.length(); j++) {
			if (s[j-1] == s[s.length()-j]) pal++;
			else break;
		}
		int melhor = pal*2;
		int left = pal, right = pal;
		for(int m = 1; m <= s.length()-2*pal; m++) {
			if (m+2*pal <= melhor) continue;
			//pr("m: %d l: %d r: %d ok: %d\n", m, pal, pal+m-1, test(pal, pal+m-1));
			if (test(pal+m, pal)) {
				melhor = m+2*pal;
				left = pal+m;
				right = pal;
			}
		}//pr("\n");
		for(int m = 1; m <= s.length()-2*pal; m++) {
			if (m+2*pal <= melhor) continue;
			//pr("m: %d l: %d r: %d ok: %d\n", m, (int)s.length()-pal-m, (int)s.length()-1-pal, test((int)s.length()-pal-m, (int)s.length()-1-pal));
			if (test(pal, pal+m)) {
				melhor = m+2*pal;
				left = pal;
				right = pal+m;
			}
		}
		//pr("%d %d\n", left, right);
		
		for(int j = 0; j < left; j++) {
			putchar(s[j]);
		}
		for(int j = sz-right; j < sz; j++) {
			putchar(s[j]);
		}putchar('\n');
	}
 	return 0;
}
