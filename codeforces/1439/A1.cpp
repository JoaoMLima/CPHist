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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef EBUG
#include "trace.h"
#else
template<typename... Args>
void trace(Args... args) {}
template<typename... Args>
void recInit(Args... args) {}
template<typename... Args>
void recEnd(Args... args) {}
#endif

int grid[107][107];
vector<ii> resp;

int n, m, t, a, b, c;
int main(){
    sc("%d\n", &t);
	while(t--) {
		resp.clear();
		sc("%d %d\n", &n, &m);
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++) {
				grid[i][j] = getchar() == '1';
				trace(i, j, grid[i][j]);
			}getchar();
		}

		for(int i = 1; i <= n-2; i++) {
			for(int j = 1; j <= m; j++) {
				if (grid[i][j]) {
					trace("toipo1");
					resp.pb({i, j});
					resp.pb({i+1, j});
					grid[i][j] = !grid[i][j];
					grid[i+1][j] = !grid[i+1][j];
					if (j > 1) {resp.pb({i+1, j-1}); grid[i+1][j-1] = !grid[i+1][j-1];}
					else {resp.pb({i+1, j+1}); grid[i+1][j+1] = !grid[i+1][j+1];}
				}
			}
		}
		for(int j = 1; j <= m-2; j++) {
			trace("toipo2");
			if (grid[n-1][j] && grid[n][j]) {
				resp.pb({n-1, j});
				resp.pb({n, j});
				resp.pb({n, j+1});
				grid[n-1][j] = !grid[n-1][j];
				grid[n][j] = !grid[n][j];
				grid[n][j+1] = !grid[n][j+1];
			} else if (grid[n-1][j]) {
				resp.pb({n-1, j});
				resp.pb({n-1, j+1});
				resp.pb({n, j+1});
				grid[n-1][j] = !grid[n-1][j];
				grid[n-1][j+1] = !grid[n-1][j+1];
				grid[n][j+1] = !grid[n][j+1];
			} else if (grid[n][j]) {
				resp.pb({n, j});
				resp.pb({n-1, j+1});
				resp.pb({n, j+1});
				grid[n][j] = !grid[n][j];
				grid[n-1][j+1] = !grid[n-1][j+1];
				grid[n][j+1] = !grid[n][j+1];
			}
		}
		if (grid[n-1][m-1] && grid[n-1][m] && grid[n][m-1] && grid[n][m]) {
			trace("toipo3");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m-1] = !grid[n][m-1];
		}
		if (grid[n-1][m-1] && grid[n-1][m] && grid[n][m-1]) {
			trace("toipo4");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m-1] = !grid[n][m-1];
		}
		if (grid[n-1][m-1] && grid[n-1][m] && grid[n][m]) {
			trace("toipo5");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m] = !grid[n][m];
		}
		if (grid[n-1][m-1] && grid[n][m-1] && grid[n][m]) {
			trace("toipo6");
			resp.pb({n-1, m-1});
			resp.pb({n, m-1});
			resp.pb({n, m});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n][m-1] = !grid[n][m-1];
			grid[n][m] = !grid[n][m];
		}
		if (grid[n-1][m] && grid[n][m-1] && grid[n][m]) {
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			resp.pb({n, m});
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m-1] = !grid[n][m-1];
			grid[n][m] = !grid[n][m];
		}
		
		if ((grid[n-1][m-1] && grid[n-1][m]) || (grid[n-1][m-1] && grid[n][m-1]) || (grid[n-1][m] && grid[n][m-1])) {
			trace("toipo7");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m-1] = !grid[n][m-1];
		}

		if ((grid[n-1][m-1] && grid[n][m]) || (grid[n-1][m] && grid[n][m])) {
			trace("toipo8");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n-1][m] = !grid[n-1][m];
			grid[n][m] = !grid[n][m];
		}
		if (grid[n][m-1] && grid[n][m]) {
			trace("toipo9");
			resp.pb({n-1, m-1});
			resp.pb({n, m-1});
			resp.pb({n, m});
			grid[n-1][m-1] = !grid[n-1][m-1];
			grid[n][m-1] = !grid[n][m-1];
			grid[n][m] = !grid[n][m];
		}
		if (grid[n-1][m-1]) {
			trace("toipo10");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m});
			resp.pb({n-1, m-1});
			resp.pb({n, m-1});
			resp.pb({n, m});
		} else if (grid[n][m]) {
			trace("toipo11");
			resp.pb({n, m});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m});
			resp.pb({n-1, m-1});
			resp.pb({n, m-1});
			resp.pb({n, m});
		} else if (grid[n-1][m]) {
			trace("toipo12");
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m});
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			resp.pb({n, m});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
		} else if (grid[n][m-1]) {
			trace("toipo13");
			resp.pb({n-1, m-1});
			resp.pb({n, m-1});
			resp.pb({n, m});
			resp.pb({n-1, m-1});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
			resp.pb({n, m});
			resp.pb({n-1, m});
			resp.pb({n, m-1});
		}
		pr("%d\n", sz(resp)/3);
		for(int i = 0; i < sz(resp); i += 3) {
			pr("%d %d %d %d %d %d\n", resp[i].fi, resp[i].se, resp[i+1].fi, resp[i+1].se, resp[i+2].fi, resp[i+2].se);
		}
	}

 	return 0;
}
