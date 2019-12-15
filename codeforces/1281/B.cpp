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
	int t;
	cin >> t;
	while(t--) {
		string s1, s2;
		cin >> s1 >> s2;
		int lt[26];
		for(int i = 0; i < 26; i++) {
			lt[i] = -1;
		}
		for(int i = 0; i < (int)s1.length(); i++) {
			lt[s1[i]-'A'] = i;
		}

		for(int i = 0; i < (int)s1.length(); i++) {
			int trocou = 0;
			for(int j = 0; j < s1[i]-'A'; j++) {
				if(lt[j] > i) {
					trocou = 1;
					swap(s1[i], s1[lt[j]]);
				}
			}
			if(trocou) break;
		}
		for(int i = 0; i < 10000; i++) {
			if(i >= s1.length() && i < s2.length()) {
				cout << s1 << "\n";
				break;
			} else if (i >= s1.length()) {
				cout << "---\n";
				break;
			} else if (s1[i] < s2[i]) {
				cout << s1 << "\n";
				break;
			} else if (s1[i] > s2[i]) {
				cout << "---\n";
				break;
			}
		}

	}
 	return 0;
}
