#include <bits/stdc++.h>
#define pr printf
#define sc scanf
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
struct pt {
    ll x, y;
    pt operator - (pt o) {
        return {x-o.x, y-o.y};
    }
    pt operator + (pt o) {
        return {x+o.x, y+o.y};
    }
    ll d() {
        return abs(x)+abs(y);
    }
};
int main() {
    ll x0, y0, ax, ay, bx, by;
    ll xs, ys, t;
    vector<pt> v;
    sc("%lld %lld %lld %lld %lld %lld", &x0, &y0, &ax, &ay, &bx, &by);
    v.pb({x0, y0});
    while(1) {
        pt p = v[v.size()-1];
        pt nx = {p.x*ax+bx, p.y*ay+by};
        v.pb(nx);
        int x;
        //pr("nx: %lld %lld\n", nx.x, nx.y);
        if ((nx-p).d() > 10000000000000000LL) {
            break;
        }
    }






    sc("%lld %lld %lld",&xs, &ys, &t);
    pt p = {xs, ys};
    int r = 0;
    for(int i = 0; i < v.size(); i++) {
        if (((p-v[i]).d()) <= t) r = max(r, 1);
        for(int j = 0; j < v.size(); j++) {
            if (((p-v[i]).d())+((v[j]-v[i]).d()) <= t) r = max(r, 1+abs(j-i));
        }
        for(int j = 0; j < i; j++) {
            for(int k = i+1; k < v.size(); k++) {
                if(((p-v[i]).d())+((v[i]-v[j]).d())+((v[j]-v[k]).d()) <= t) {
                    r = max(r, k-j+1);
                }
                if(((p-v[i]).d())+((v[i]-v[k]).d())+((v[j]-v[k]).d()) <= t) {
                    r = max(r, k-j+1);
                }
            }
        }
    }
    pr("%d\n", r);

    
    return 0;
}