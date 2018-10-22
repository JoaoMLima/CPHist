#include <bits/stdc++.h>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
    if (s1.length() != s2.length()) {
        printf("NO\n"); return 0;
    }
    for(int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[s2.length() - 1 - i]) {
            printf("NO\n"); return 0;
        }
    }
    printf("YES\n"); return 0;
    return 0;
}