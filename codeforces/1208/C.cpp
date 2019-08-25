#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a;
int li[1000][1000];
int total = 0;
int main(){
	sc("%d", &n);
	for(int i = 0; i < n/4; i++) {
		for(int j = 0; j < n/4; j++) {
			li[i*4][j*4] = 8+total;
			li[i*4][j*4+1] = 9+total;
			li[i*4][j*4+2] = 1+total;
			li[i*4][j*4+3] = 13+total;
			li[i*4+1][j*4] = 3+total;
			li[i*4+1][j*4+1] = 12+total;
			li[i*4+1][j*4+2] = 7+total;
			li[i*4+1][j*4+3] = 5+total;
			li[i*4+2][j*4] = 0+total;
			li[i*4+2][j*4+1] = 2+total;
			li[i*4+2][j*4+2] = 4+total;
			li[i*4+2][j*4+3] = 11+total;
			li[i*4+3][j*4] = 6+total;
			li[i*4+3][j*4+1] = 10+total;
			li[i*4+3][j*4+2] = 15+total;
			li[i*4+3][j*4+3] = 14+total;
			total += 16;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j != 0) pr(" ");
			pr("%d", li[i][j]);
		}pr("\n");
	}
	/*
	for(int i = 0; i < n; i++) {
		int x = 0;
		for(int j = 0; j < n; j++) {
			x ^= li[i][j];
		}pr("%d\n", x);
	}
	for(int i = 0; i < n; i++) {
		int x = 0;
		for(int j = 0; j < n; j++) {
			x ^= li[j][i];
		}pr("%d\n", x);
	}*/
 	return 0;
}
