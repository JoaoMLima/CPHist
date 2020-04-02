#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;

int n;

int grid[10][10];
int grid2[10][10];
int gridori[10][10];

int main(){
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			gridori[i][j] = getchar();
			grid[i][j] = (gridori[i][j] != '.');
			
			if (j%3 == 2) getchar();
		}
		if (i%3 == 2 && i != 8) getchar();
	}
	int a, b;
	sc("%d %d", &a, &b);
	a--; b--;
	ii pos = {a%3, b%3};
	int ok = 0;
	for(int i = 0; i < 9; i++) {
		if (i/3 != a%3) continue;
		for(int j = 0; j < 9; j++) {
			if (j/3 != b%3 || grid[i][j]) continue;
			gridori[i][j] = '!';
			ok = 1;
		}
	}
	if (!ok) {
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if (grid[i][j]) continue;
				gridori[i][j] = '!';
			}
		}
	}
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			putchar(gridori[i][j]);
			if (j%3 == 2 && j != 8) putchar(' ');
		}putchar('\n');
		if (i%3 == 2 && i != 8) putchar('\n');
	}
 	return 0;
}
