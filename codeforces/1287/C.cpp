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

int n, t, a, b, c;
int li[110];
int main(){
	sc("%d", &n);
	int primeiro = -1;
	int ultp = -1;
	vector<int> qtd1;
	vector<int> qtd0;
	int qtdpar = n/2;
	int qtdimpar = n/2+(n%2);
	int inevitavel = 0;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		li[i] = a;
		if (li[i] % 2 == 0 && li[i] != 0) qtdpar--;
		else if (li[i] % 2 == 1) qtdimpar--;
		if (a != 0) {
			if (ultp != -1) {
				if (li[i] % 2 == li[ultp] % 2) {
					if (li[i-1] == 0) {
						if (li[i] % 2 == 0) {
							qtd0.pb(i-1-ultp);
						} else {
							qtd1.pb(i-1-ultp);
						}
					}
				} else {
					inevitavel++;
				}
			}
			if (ultp == -1) {
				primeiro = i;
			}
			ultp = i;
		}
	}
	if (ultp == -1) {
		if (n == 1) pr("0\n");
		else pr("1\n");
		return 0;
	}
	//cout << "in " << inevitavel << endl;
	sort(qtd1.begin(), qtd1.end());
	sort(qtd0.begin(), qtd0.end());
	for(int x : qtd1) {
		//cout << "q1: " << x << endl;
		if (qtdimpar >= x) {
			qtdimpar -= x;
		} else {
			inevitavel+= 2;
		}
	}
	for(int x : qtd0) {
		//cout << "q0: " << x << endl;
		if (qtdpar >= x) {
			qtdpar -= x;
		} else {
			inevitavel+= 2;
		}
	}
	if (primeiro != 0) {
		//cout << "pri: " << primeiro << " " << qtdimpar << endl;
		if (li[primeiro] % 2 == 0) {
			if (qtdpar >= primeiro) qtdpar -= primeiro;
			else inevitavel++;
		} else {
			if (qtdimpar >= primeiro) qtdimpar -= primeiro;
			else inevitavel++;
		}
	}
	//cout << "in " << inevitavel << endl;
	if (ultp != n-1) {
		if (li[ultp] % 2 == 0) {
			if (qtdpar >= n-1-(ultp)) qtdpar -= n-1-(ultp);
			else inevitavel++;
		} else {
			if (qtdimpar >= n-1-(ultp)) qtdimpar -= n-1-(ultp);
			else inevitavel++;
		}
	}
	pr("%d\n", inevitavel);

 	return 0;
}