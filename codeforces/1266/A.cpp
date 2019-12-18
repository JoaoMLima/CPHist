#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c;
int main(){
	sc("%d\n", &n);
	for(int i = 0; i < n; i++) {
		int t = 0;
		int h0 = 0;
		int p = 0;
		char ch = getchar();
		while(ch != '\n') {
			if(ch == '0') {
				h0 = 1;
			}
			if(!( ((int)(ch-'0')) &1)) p++;
			t = (t + (int)(ch-'0'))%3;
			ch = getchar();
		}
		if(h0 && t == 0 && p > 1) pr("red\n");
		else pr("cyan\n");

	}
 	return 0;
}
