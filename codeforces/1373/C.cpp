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

int n, t; ll a, b, c;
char s[1000007];
int first[1000007];
int main(){
	sc("%d\n", &t);

	while(t--) {
		n = 0;
		char ch = getchar();
		while(ch == '-' || ch == '+') {
			s[n++] = ch;
			ch = getchar();
		}
		//pr("n: %d\n", n);
		int total = 0;
		for(int i = 0; i <= n+1; i++) {
			first[i] = -1;
		}
		for(int i = 0; i < n; i++) {
			if (s[i] == '-') total++;
			else total--;
			//pr("total: %d first: %d i: %d\n", total, first[total], i);
			if (total >= 0 && first[total] == -1) {
				first[total] = i;
			}
		}
		/*
		for(int i = 0; i <= n+1; i++) {
			pr("%d ", first[i]);
		}pr("\n");
		*/
		ll resp = 0LL;
		for(int i = 1; i <= n+1; i++) {
			if (first[i] == -1) {
				resp += n;
				break;
			}
			resp += first[i]+1;
		}
		pr("%lld\n", resp);
	}
 	return 0;
}
