#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define pb push_back
#define mod 1000000007LL

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef long double ld;
ll modpow(ll a, ll b) {
    if(b == 0) return 1;
    if(b & 1) return a*modpow(a, b-1)%mod;
    ll r = modpow(a, b>>1);
    return r*r%mod;
}

int main() {
    int n;
    sc("%d", &n);
    vector<int> v;
    int inv = 0;
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            for(int j = n; j > 0; j--) {
                v.pb(j);
            }
        } else {
            for(int j = 1; j <= n; j++) {
                v.pb(j);
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        int prin = 0;
        for(int j = 0; j < v.size(); j++) {

            if(v[j] == i) {
                if(prin) pr(" ");
                pr("%d", j+1);
                prin = 1;
            }
        }
        pr("\n");
    }
    return 0;
}