#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define MAX 200010
#define dis(i,j) dis[(i*(m+2))+j]
#define cp(i,j) cp[(i*(m+2))+j]
 
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
 
int n, m, a, b, c;
int dis[3000010];
int cp[3000010];
 
void retrieve() {
	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			dis(i,j) = cp(i,j);
		}
	}
}
 
int query(ii pos, int d) {
	d--;
	int maxi = min(pos.first+d,n+1), mini = max(pos.first-d, 0);
	int maxj = min(pos.second+d,m+1), minj = max(pos.second-d, 0);
	int res = dis(maxi,maxj);
	int g = mini-1, h = minj-1;
	if (mini) res -= dis(g,maxj);
	if (minj) res -= dis(maxi,h);
	if (mini && minj) res += dis(g,h);
	return (res) ? 1 : 0;
}
 
queue<ii> st;
 
int main(){
	sc("%d %d\n", &n, &m);
	int total = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char ch = getchar();
			if (ch == 'X') {
				dis(i,j) = 10000000;
				total++;
			}
		}
		getchar();
	}
	
	for(int i = 0;i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			if (dis(i,j) == 0) st.push({i, j});
		}
	}
	
	while(!st.empty()) {
		ii f = st.front(); st.pop();

		for(int i = -1; i <= 1; i++) {
			for(int j = -1; j<= 1; j++) {
				int g = f.first+i, h = f.second+j;
				if (g > n+1 || g < 0 || h > m+1 || h < 0) continue;
				if (dis(g,h) > dis(f.first,f.second)+1) {
					dis(g,h) = dis(f.first,f.second)+1;
					st.push({g, h});
				}
			}
		}
	}
	
	for(int i = 0; i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			//pr("%d %d\n", i, j);
			cp(i,j) = dis(i,j);
		}
	}
	/*
	for(int i = 0;i <= n+1; i++) {
		for(int j = 0; j <= m+1; j++) {
			pr("%d ", dis(i,j));
		}pr("\n");
	}pr("\n");
*/
	int l = 1, r = min(n+2, m+2)/2;
	int resp = 1;
	while(l <= r) {
		int md = (l+r)/2;
		for(int i = 0; i <= n+1; i++) {
			for(int j = 0; j <= m+1; j++) {
				int g = i-1, h = j-1;
				dis(i,j) = (cp(i,j) >= md) ? 1 : 0;
				if (i) dis(i,j) += dis(g,j);
				if (j) dis(i,j) += dis(i,h);
				if (i && j) dis(i,j) -= dis(g,h);
			}
		}
		int cnt = 0;
		for(int i = 0; i <= n+1; i++) {
			for(int j = 0; j <= m+1; j++) {
				ii f = {i, j};
				cnt += query(f, md);
			}
		}
		//pr("%d %d %d\n", md, cnt, total);
		if (cnt >= total) {resp = md; l = md+1;}
		else r = md-1;
		
	}
	pr("%d\n", resp-1);
	for(int i = 1;i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			//pr("%d %d\n", i, j);
			if (cp(i,j) >= resp) {
				pr("X");
			} else {
				pr(".");
			}
		}pr("\n");
	}
	
 	return 0;
}