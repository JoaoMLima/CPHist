#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 100007
#define MOD 1000000007
#define MODL 1000000007LL
#define EPS 1e-12
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

ll iv[30][2];
void prin(vector<int> &v) {
	for(int x : v) cout << x << " ";
	cout << endl;
}

void resp (vector<int> &v, int b){
	vector<int> m1, m2;
	int qtd0 = 0, qtd1 = 0;
	for(int x : v) {
		if (x&(1<<b)) {
			iv[b][1] += qtd0;
			m2.pb(x);
			qtd1++;
		} else {
			iv[b][0] += qtd1;
			m1.pb(x);
			qtd0++;
		}
	}
	if (b > 0 && !m1.empty()) {
		resp(m1, b-1);
	}
	if (b > 0 && !m2.empty()) {
		resp(m2, b-1);
	}
}


vector<int> li;
int n, t, a, b, c;
int main(){
	sc("%d", &n);
	int atual = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		li.pb(a);
	}
	resp(li, 29);
	ll r = 0LL;
	ll cnt = 0LL;
	for(int i = 0; i < 30; i++) {
		if (iv[i][1] < iv[i][0]) {
			r ^= (1<<i);
			cnt += iv[i][1];
		} else {
			cnt += iv[i][0];
		}
	}
	pr("%lld %lld\n", cnt, r);
	
 	return 0;
}
