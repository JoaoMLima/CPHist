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

int n, a, b, c, t, k;
int p[200010];
stack<ii> rollback;

void rollbacks() {
	while(!rollback.empty()) {
		ii f = rollback.top(); rollback.pop();
		p[f.fi] = f.se;
	}
}

int find(int a) {
	if (p[a] == a) return a;
	rollback.push({a, p[a]});
	return p[a] = find(p[a]);
}

void uni(int a, int b) {
	//cout << a << " " << b << " " << k << endl;
	a = find(a), b = find(b);
	if (rand() & 1) {
		rollback.push({a, p[a]});
		p[a] = b;
	} else {
		rollback.push({b, p[b]});
		p[b] = a;
	}
}

map<int, int> m[200010];
int sum[200010];
int maxi[200010];
int main(){
	sc("%d", &t);
	for(int i = 0; i < 200010; i++) {
			p[i] = i;
		}
	while(t--) {
		sc("%d %d", &n, &k);
		//cout << "teste " << k << endl;
		
		for(int i = 0; i < n; i++) {
			if (n-1-i > i) {
				uni(i, n-1-i);
			}
			if (i+k < n) {
				//cout << i << " " << k << endl;
				uni(i, i+k);
			}
		}
		set<int> gr;
		string s;
		cin >> s;
		//cout << s;
		
		for(int i = 0; i < n; i++) {
			gr.insert(find(i));
			m[find(i)][s[i]]++;
			sum[find(i)]++;
			maxi[find(i)] = max(maxi[find(i)], m[find(i)][s[i]]);
		}
		int resp = 0;

		for( int g : gr) {
			resp += sum[g]-maxi[g];
		}

		for(int i = 0; i < n; i++) {
			m[find(i)][s[i]] = 0;
			sum[find(i)] = 0;
			maxi[find(i)] = 0;
		}

		rollbacks();

		pr("%d\n", resp);
	}
 	return 0;
}
