#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)
#define INF 1000000000


typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
int t, r, c, k;

ii farm[110][110];
ii nxt(ii ce) {
	ii ce1 = ce;
	if (ce.second % 2) {
		if (ce.first) {
			ce1.first--;
		} else {
			ce1.second++;
		}
	} else {
		if (ce.first == r-1) {
			ce1.second++;
		} else {
			ce1.first++;
		}
	}
	return ce1;
}

int main(){
	vector<char> corresp;
	for(char i = 0; i < (char)26; i++) {
		corresp.pb('a'+i);
	}
	for(char i = 0; i < (char)26; i++) {
		corresp.pb('A'+i);
	}
	for(char i = 0; i < (char)10; i++) {
		corresp.pb('0'+i);
	}
	/*
	for(int i = 0; i < (int)corresp.size(); i++) {
		pr("%c\n", corresp[i]);
	}*/
    
	sc("%d\n", &t);
	while(t--) {
		sc("%d %d %d\n", &r, &c, &k);
		int rc = 0;
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				farm[i][j] = {0, -1};
			}
		}

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				char ch = getchar();
				if (ch == 'R') {
					farm[i][j].first = 1;
					rc++;
				}
			}getchar();
		}
		


		int mini = rc/k;
		int maxi = (rc/k) + ((rc%k) ? 1 : 0);
		int qtdmaxi = rc%k;
		//pr("%d %d %d\n", qtdmaxi, maxi, mini);
		int chk = 0;
		ii cell = {0, 0};
		int accu = 0;
		while(true) {
			if (farm[cell.first][cell.second].first) {
				accu++;
			}
			if ((accu > maxi && qtdmaxi) || (accu > mini && !qtdmaxi)) {
				chk++;
				if (accu > maxi && qtdmaxi) qtdmaxi--;
				accu = 1;
			}
			farm[cell.first][cell.second].second = chk;
			
			
			ii next = nxt(cell);
			if (next.second >= c) {
				break;
			}
			cell = nxt(cell);
		}
		/*
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				pr(" %d", farm[i][j].second);
			}pr("\n");
		}*/

		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				putchar(corresp[farm[i][j].second]);
			}putchar('\n');
		}//putchar('\n');

	}
	
 	return 0;
}
