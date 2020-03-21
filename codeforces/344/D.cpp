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

int main(){
	string s;
	cin >> s;
	stack<int> st; // 0 = sobecima 1 = descecima 2 = sobebaixo 3 = descebaixo
	for(int i = 0; i < s.length(); i++) {
		int wr = (i & 1) +(s[i] == '-' ? 2 : 0);
		if (!st.empty() && st.top() == (wr^1)) st.pop();
		else st.push(wr);
	}
	if(st.empty()) pr("Yes\n");
	else pr("No\n");
	
 	return 0;
}
