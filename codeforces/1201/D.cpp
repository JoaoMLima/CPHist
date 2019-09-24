#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;
pair<int, int> tmp[200010];

struct row {int y, minx, maxx;};
vector<row> treasures;
set<int> columns;
ll dpt[2][200010];
int getNext(int col) {
	set<int>::iterator it = columns.lower_bound(col);
	if(it != columns.end()) return *it;
	else return *prev(it);
}
int getPrev(int col) {
	set<int>::iterator it = columns.lower_bound(col);
	if(it != columns.begin()) return *prev(it);
	else return *it;
}

ll dp(int a, int b) {
	if(dpt[a][b] == -1) {
		dpt[a][b] = treasures[b].maxx-treasures[b].minx;
		if(b != treasures.size()-1) {
			int x, y = b+1;
			if (a) x = treasures[b].minx;
			else x = treasures[b].maxx;
			int c1 = min(abs(getPrev(x)-x)+abs(treasures[y].minx-getPrev(x)), abs(getNext(x)-x)+abs(treasures[y].minx-getNext(x)));
			int c2 = min(abs(getPrev(x)-x)+abs(treasures[y].maxx-getPrev(x)), abs(getNext(x)-x)+abs(treasures[y].maxx-getNext(x)));
			dpt[a][b] += min(c1+dp(0, y), c2+dp(1, y))+treasures[y].y-treasures[b].y;
		}
	}
	return dpt[a][b];
}

int n, m, k, q;
int main(){
	int a, b, c;
	memset(dpt, -1, sizeof dpt);
	memset(tmp, -1, sizeof tmp);
	sc("%d %d %d %d", &n, &m, &k, &q);
	for(int i = 0; i < k; i++) {
		sc("%d %d", &a, &b);
		if(tmp[a].fi == -1)  tmp[a] = {b, b};
		else tmp[a] = {min(tmp[a].fi, b), max(tmp[a].se, b)};
	}
	for(int i = 0; i < 200010; i++) {
		if(tmp[i].fi != -1) treasures.pb({i, tmp[i].fi, tmp[i].se});
	}
	for(int i = 0; i < q; i++) {
		sc("%d", &a);
		columns.insert(a);
	}
	if(treasures[0].y == 1) {
		int c1 = treasures[0].minx-1, c2 = treasures[0].maxx-1;
		pr("%lld\n", min(c1+dp(0, 0), c2+dp(1, 0)));
	} else {
		int x = 1, y = 0;
		int c1 = min(abs(getPrev(x)-x)+abs(treasures[y].minx-getPrev(x)), abs(getNext(x)-x)+abs(treasures[y].minx-getNext(x)));
		int c2 = min(abs(getPrev(x)-x)+abs(treasures[y].maxx-getPrev(x)), abs(getNext(x)-x)+abs(treasures[y].maxx-getNext(x)));
		pr("%lld\n", min(c1+dp(0, 0), c2+dp(1, 0))+treasures[y].y-1);
	}
	
	//sc("%d", &);
	//sc("%d %d", &, &);
	//sc("%d %d %d", &, &, &);
	//sc("%d %d %d %d", &, &, &, &);
	//for (int i = 0; i < ; i++)
 	return 0;
}
