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
int main(){
	sc("%d", &t);
	while(t--) {
		string s;
		cin >> s;
		int qtd0 = 0, qtd1 = 0;
		for(char ch : s) {
			if (ch == '0') qtd0++;
			else qtd1++;
		}
		int mini = min(qtd0, qtd1);
		if (mini&1) pr("DA\n");
		else pr("NET\n");
	}
 	return 0;
}
