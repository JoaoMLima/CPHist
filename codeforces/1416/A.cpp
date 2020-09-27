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

vector<ii> pos;
set<ii> blocks;


int li[3*MAX];
int dist[3*MAX];
int last[3*MAX];
int best[3*MAX];
int n, t, a, b, c;
int main(){
	sc("%d", &t);
	while(t--) {
		sc("%d", &n);
		for(int i = 0; i <= n; i++) {
			dist[i] = -1;
			last[i] = -1;
			best[i] = 1000000;
		}
		for(int i = 0; i < n; i++) {
			sc("%d", li+i);
			int x = max(n-i, i+1);
			if (last[li[i]] == -1) {
				last[li[i]] = i;
				dist[li[i]] = i+1;
			} else {
				dist[li[i]] = max(dist[li[i]], i-last[li[i]]);
				last[li[i]] = i;
			}
		}
		for(int i = 0; i <= n; i++) {
			if (last[i] != -1) {
				dist[i] = max(dist[i], n-last[i]);
				best[dist[i]] = min(best[dist[i]], i);
			}
		}
		for(int i = 2; i <= n; i++) {
			best[i] = min(best[i], best[i-1]);
		}
		for(int i = 1; i <= n; i++) {
			if (i > 1) pr(" ");
			if (best[i] == 1000000) pr("-1");
			else pr("%d", best[i]);
		}pr("\n");
	}
 	return 0;
}
