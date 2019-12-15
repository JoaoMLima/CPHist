#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<int, int> ii;

int n, a, b, c, x;
char s[1000010];
int main(){
	int t;
	sc("%d\n", &t);
	while(t--) {
		n = 0;
		sc("%d\n", &x);
		char ch = getchar();
		while(ch != '\n') {
			s[n++] = ch;
			ch = getchar();
		}
		int lng = n;
		int lng2 = n;
		for(int i = 0; i < x;) {
			int nxt = s[i];
			if(s[i] == '1') {
				i++;
			} else if (s[i] == '2') {
				i++;
				int tmp = lng-i;
				int tmp2 = lng2-i;
				for(int j = i; j < i+tmp2 && j+tmp2 < 1000005; j++) {
					s[j+tmp2] = s[j];
				}
				lng = (((lng + tmp) % 1000000007)+1000000007) % 1000000007;
				lng2 = min(lng2 + tmp2, 100000000);
			} else {
				i++;
				int tmp = lng-i;
				int tmp2 = lng2-i;
				for(int j = i; j < i+tmp2 && j+tmp2 < 1000005; j++) {
					s[j+tmp2] = s[j];
				}
				for(int j = i+tmp2; (j < i+tmp2+tmp2) && j+tmp2 < 1000005; j++) {
					s[j+tmp2] = s[j];
				}
				lng = (((((lng + tmp) % 1000000007) + tmp) % 1000000007)+1000000007) % 1000000007;
				lng2 = min(lng2 + tmp2 + tmp2, 100000000);
			}
			//pr("%d %d\n", i, lng);
		}pr("%d\n", lng);
	}
 	return 0;
}
