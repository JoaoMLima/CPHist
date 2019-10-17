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
    ll t, a, b, c;
    sc("%lld %lld", &a, &b);
    pr("%lld\n", modpow(modpow(2LL, b)-1LL, a));
    return 0;
}