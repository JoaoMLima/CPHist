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

int n, a, b, c;
int arr[60] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
int main(){
	sc("%d", &n);
	vector<int> v;
	for(int i = 0; i < n; i++) {
		sc("%d", &a);
		v.pb(a);
	}
	for(int j = 0; j+(int)v.size() <= 60; j++) {
		int ok = 1;
		for(int i = 0; i < (int)v.size(); i++) {
			if (v[i] != arr[j+i]) ok = 0;
		}
		if (ok){
			pr("Yes\n");return 0;
		}
	}
	pr("No\n");
 	return 0;
}
