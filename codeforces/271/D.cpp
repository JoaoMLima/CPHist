#include <bits/stdc++.h>
using namespace std;
#define trace1(a) cout << a << '\n';
#define trace2(a, b) cout << a << ' ' << b << '\n';
#define trace3(a, b, c) cout << a << ' ' << b << ' ' << c << '\n';
#define trace4(a, b, c, d) cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
#define trace5(a, b, c, d, e) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << '\n';
#define trace6(a, b, c, d, e, f) cout << a << ' ' << b << ' ' << c << ' ' << d << ' ' << e << ' ' << f << '\n';
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 2000000
#define mod 1000000007
#define md(x) (x) % mod;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ps push
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1000000000
#define INFd 1e9
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;
int n = 0, k, r = 0;
struct Trie {
	map<char, Trie> node;
};
char li[1500];
bool isGood[26];
void subs(int i, Trie &t, int bads) {
	if (i >= n) return;
	if(!isGood[li[i]-'a']) bads++;
	if (bads <= k) {
		if (!(t.node.count(li[i]))) r++;
		subs(i+1, t.node[li[i]], bads);
	}
}
int main(){
	char ch = getchar();
	while(ch != '\n') {
		li[n++] = ch;
		ch = getchar();
	}
	for(int i = 0; i < 26; i++) {
		ch = getchar();
		isGood[i] = (ch == '1');
	}
	sc("%d", &k);
	Trie root;
	for(int i = 0; i < n; i++) {
		subs(i, root, 0);
	}
	pr("%d\n", r);
 	return 0;
}