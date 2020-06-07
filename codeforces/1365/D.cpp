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

int n, t, a, b,m;
int maze[57][57];
int vi[57][57];
int main(){
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d\n", &n, &m);
		vector<ii> badguy;
		vector<ii> goodguy;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				vi[i][j] = 0;
				maze[i][j] = getchar();
				if (maze[i][j] == 'B') badguy.pb({i, j});
				if (maze[i][j] == 'G') goodguy.pb({i, j});
			}getchar();
		}
		//cout << "Terminou" << endl;
		int ok = 1;
		for(ii bg : badguy) {
			if (bg.fi > 0) {
				if (maze[bg.fi-1][bg.se] == 'G') {
					ok = 0;
				} else if (maze[bg.fi-1][bg.se] == '.') {
					maze[bg.fi-1][bg.se] = '#';
				}
			}
			if (bg.fi < n-1) {
				if (maze[bg.fi+1][bg.se] == 'G') {
					ok = 0;
				} else if (maze[bg.fi+1][bg.se] == '.') {
					maze[bg.fi+1][bg.se] = '#';
				}
			}
			if (bg.se > 0) {
				if (maze[bg.fi][bg.se-1] == 'G') {
					ok = 0;
				} else if (maze[bg.fi][bg.se-1] == '.') {
					maze[bg.fi][bg.se-1] = '#';
				}
			}
			if (bg.se < m-1) {
				if (maze[bg.fi][bg.se+1] == 'G') {
					ok = 0;
				} else if (maze[bg.fi][bg.se+1] == '.') {
					maze[bg.fi][bg.se+1] = '#';
				}
			}
		}
		if (!ok) {
			pr("No\n");
			continue;
		}
		queue<ii> q;
		if (maze[n-1][m-1] != 'B' && maze[n-1][m-1] != '#') {
			q.push({n-1, m-1});
			vi[n-1][m-1] = 1;
		}
		while(!q.empty()) {
			ii f = q.front();q.pop();
			if (f.fi > 0 && maze[f.fi-1][f.se] != '#' && !vi[f.fi-1][f.se]) {
				q.push({f.fi-1, f.se});
				vi[f.fi-1][f.se] = 1;
			}
			if (f.fi < n-1 && maze[f.fi+1][f.se] != '#' && !vi[f.fi+1][f.se]) {
				q.push({f.fi+1, f.se});
				vi[f.fi+1][f.se] = 1;
			}

			if (f.se > 0 && maze[f.fi][f.se-1] != '#' && !vi[f.fi][f.se-1]) {
				q.push({f.fi, f.se-1});
				vi[f.fi][f.se-1] = 1;
			}
			if (f.se < m-1 && maze[f.fi][f.se+1] != '#' && !vi[f.fi][f.se+1]) {
				q.push({f.fi, f.se+1});
				vi[f.fi][f.se+1] = 1;
			}
		}

		for(ii bg : goodguy) {
			if (!vi[bg.fi][bg.se]) ok = 0;
		}

		if (!ok) {
			pr("No\n");
			continue;
		}
		pr("Yes\n");
	}
 	return 0;
}
