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

int MD(int x) {
	if(x < 0) return x+MOD;
	if(x >= MOD) return x-MOD;
	return x;
}

ll MDL(ll x) {
	return (x%MODL+MODL)%MODL;
}

ll modpow(ll a, ll b, ll m) {
	if (!b) return 1LL;
	if (b&1LL) return a*modpow(a, b-1, m)%m;
	ll r = modpow(a, b>>1, m);
	return r*r%m;
}

//m prime
ll invmod(ll a , ll m) {
	return modpow(a, m-2, m);
}
char v[200007];

int dpt[200007][3];

int n;

int dp(int i, int sobra) {//pos [0, n-1] //sobra [0-2]
	//trace(i, sobra);
	if (dpt[i][sobra] == -1) {
		int qtd = (v[(i)%n] != 'R') + (v[(i+1)%n] != 'L');
		int posinicial = n+sobra;
		int mini = 200007;
		if (sobra == 0) {
			if (i <= n-4) { // adiciona distancia 0
				mini = min(mini, qtd+dp(i+2, sobra));
			}else if (i == n-2) {
				mini = min(mini, qtd);
			}
			if (i <= n-5) { // adiciona distancia 1
				mini = min(mini, qtd+dp(i+3, sobra));
			} else if (i == n-3) {
				mini = min(mini, qtd);
			}
			int qtd2 = (v[(i+2)%n] != 'L') + (v[(i+3)%n] != 'R');
			if (i <= n-6) {// adiciona distancia 2
			//trace(i, qtd, qtd2, dp(i+4, sobra));
				mini = min(mini, qtd+qtd2+dp(i+4, sobra));
			} else if (i == n-4) {
				mini = min(mini, qtd+qtd2);
			}
		} else if (sobra == 1) {
			if (i <= n-3) { // adiciona distancia 0
				mini = min(mini, qtd+dp(i+2, sobra));
			}else if (i == n-1) {
				mini = min(mini, qtd);
			}
			if (i <= n-4) { // adiciona distancia 1
				mini = min(mini, qtd+dp(i+3, sobra));
			} else if (i == n-2) {
				mini = min(mini, qtd);
			}
			int qtd2 = (v[(i+2)%n] != 'L') + (v[(i+3)%n] != 'R');
			if (i <= n-5) {
				mini = min(mini, qtd+qtd2+dp(i+4, sobra));
			} else if (i == n-3) {
				mini = min(mini, qtd+qtd2);
			}
		} else {
			if (i <= n-3) { // adiciona distancia 0
				mini = min(mini, qtd+dp(i+2, sobra));
			}
			if (i <= n-4) { // adiciona distancia 1
				mini = min(mini, qtd+dp(i+3, sobra));
			} else if (i == n-1) {
				mini = min(mini, qtd);
			}
			int qtd2 = (v[(i+2)%n] != 'L') + (v[(i+3)%n] != 'R');
			if (i <= n-5) {
				mini = min(mini, qtd+qtd2+dp(i+4, sobra));
			} else if (i == n-2) {
				mini = min(mini, qtd+qtd2);
			}
		}
		dpt[i][sobra] = mini;
	}
	return dpt[i][sobra];
}


int t, a, b, c;
int main(){
	sc("%d\n", &t);
	while(t--) {
		ll k;
		sc("%d\n", &n);
		for(int i = 0; i < n; i++) {
			v[i] = getchar();
		}getchar();

		int inicial = 0;
		for(int i = 1; i < n; i++) {
			if (v[i] != v[0]) {inicial = i;break;}
		}
		if (inicial == 0) {
			pr("%d\n", (n / 3) + (n%3 ? 1 : 0));
			continue;
		}
		int ant = 0;
		int resp = 0;
		for(int i = 1; i < n; i++) {
			if (v[(i+inicial)%n] != v[(i+n-1+inicial)%n]) {
				resp += (i-ant)/3;
				ant = i;
			}
		}
		resp += (n-ant)/3;
		pr("%d\n", resp);
		//trace(dp(0, 0), dp(1, 1), dp(2,2));
		/*
		pr("\t");
		for(int j = 1; j < 2; j++) {
			pr("%d\t", j);
		}pr("\n");
		for(int i = 0; i < n; i++) {
			pr("%d\t", i);
			for(int j = 1; j < 2; j++) {
				pr("%d\t", dpt[i][j]);
			}pr("\n");
		}
		*/
	}
 	return 0;
}
