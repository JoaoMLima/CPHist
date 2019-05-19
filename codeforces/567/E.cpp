#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define forn(x, n) for(int x = 0; x < n; x++)
#define maxn "100000"
#define mod "1000000007"
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF 1e18
#define INFd 1e9
#define left(x) ((x<<1)+1)
#define right(x) ((x<<1)+2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

void prVector(vi v) {cout << "{";for(int i = 0; i < (int)v.size()-1; i++) {cout << v[i] << ", ";} cout << v[(int)v.size()-1] << "}";}

//Trace dinamico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

//DP debug
int recNum = 0;
void prTabs() { range(recNum) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}
int n, m, s, t, a, b, c;
ll distToS[100001];
ll distToT[100001];
vector<ii> g[100001];
vector<ii> g2[100001];
pair<int, ii> edges[100001];
int visi1[100001];
int visi2[100001];
map<ll, pair<int, ii> > bit;
pair<int, ii> query(ll i) {
    i += 2;
    pair<int, ii> s = {0, {0,0}};
    while(i) {
        if (bit.count(i)) {
            pair<int, ii> aux = bit[i];
            s.fi += aux.fi; s.se.fi += aux.se.fi; s.se.se += aux.se.se;
        }
        i -= i & (-i);
    }
    return s;
}
void update(ll i, pair<int, ii> v) {
    i += 2;
    while(i <= 1e12) {
        if(bit.count(i)) {
            pair<int, ii> ant = bit[i];
            ant.fi += v.fi; ant.se.fi += v.se.fi; ant.se.se += v.se.se;
            bit[i] = ant;
        }
        else bit[i] = v;
        i += i & (-i);
    }
}
/*
int query2(ll i) {
    i += 2;
    int s = 0;
    while(i) {
        s += (bit2.count(i)) ? bit2[i] : 0;
        i -= i & (-i);
    }
    return s;
}
void update2(ll i, int v = 1) {
    i += 2;
    while(i <= 1e12) {
        if(bit2.count(i)) bit2[i] += v;
        else bit2[i] = v;
        i += i & (-i);
    }
}
int query3(ll i) {
    i += 2;
    int s = 0;
    while(i) {
        s += (bit3.count(i)) ? bit3[i] : 0;
        i -= i & (-i);
    }
    return s;
}
void update3(ll i, int v = 1) {
    i += 2;
    while(i <= 1e12) {
        if(bit3.count(i)) bit3[i] += v;
        else bit3[i] = v;
        i += i & (-i);
    }
}*/
int hasIntersection(ll l, ll r) {
    //trace("intersections:", query1(r-1)-query1(l-1) + query2(r)-query2(l) + query3(l));
    pair<int, ii> q1 = query(r-1);
    pair<int, ii> q2 = query(l-1);
    pair<int, ii> q3 = query(r);
    pair<int, ii> q4 = query(l);
    return (q1.fi- q2.fi + q3.se.fi - q4.se.fi + q4.se.se - 3 > 0);
    //return (query1(r-1)-query1(l-1) + query2(r)-query2(l) + query3(l) - 3 > 0);
}
int main(){
    sc("%d %d %d %d\n", &n, &m, &s, &t);
    for(int i = 0; i < 100001; i++) {
        distToS[i] = INF;
        distToT[i] = INF;
    }
    distToS[s] = 0;
    distToT[t] = 0;
    for(int i = 0; i < m; i++) {
        sc("%d %d %d", &a, &b, &c);
        g[a].pb({b, c});
        g2[b].pb({a, c});
        edges[i] = {a, {b, c}};
    }
    priority_queue<pair<ll, int> , vector<pair<ll, int> >, greater<pair<ll, int> > > pq;
    pq.push({0, s});
    while(!pq.empty()) {
        pair<ll, int> f = pq.top();pq.pop();
        if(f.fi == distToS[f.se] && !visi1[f.se]) {
            visi1[f.se] = 1;
            for(ii i : g[f.se]) {
                //trace(f.se, i.fi, f.fi + i.se, distToS[i.fi].fi, distToS[i.fi].se);
                if (f.fi + i.se < distToS[i.fi]) {
                    distToS[i.fi] = f.fi + i.se;
                    pq.push({f.fi + i.se, i.fi});
                }
            }
        }
    }
    pq.push({0, t});
    while(!pq.empty()) {
        pair<ll, int> f = pq.top();pq.pop();
        if(f.fi == distToT[f.se] && !visi2[f.se]) {
            visi2[f.se] = 1;
            for(ii i : g2[f.se]) {
                if (f.fi + i.se < distToT[i.fi]) {
                    distToT[i.fi] = f.fi + i.se;
                    pq.push({f.fi + i.se, i.fi});
                }
            }
        }
    }/*
    trace("distToS:");
    for(int i = 1; i <= n; i++) {
        trace("{", distToS[i].fi, ", ", distToS[i].se, "}");
    }
    trace("distToT:");
    for(int i = 1; i <= n; i++) {
        trace("{", distToT[i].fi, ", ", distToT[i].se, "}");
    }*/
    //trace("aquiiii1");
    for(int i = 0; i < m; i++) {
        pair<int, ii> ed = edges[i];
        //trace(ed.fi, ed.se.fi, ed.se.se);
        if (distToS[ed.fi] + distToT[ed.se.fi] + ed.se.se == distToS[t]) {
            //trace(ed.fi, ed.se.fi);
            //trace("update1", distToS[ed.fi]);
            //trace("update2", distToS[ed.se.fi]);
            update(distToS[ed.fi], {1, {0, 1}});
            update(distToS[ed.se.fi], {0, {1, -1}});
            /*
            update1(distToS[ed.fi], 1);
            update3(distToS[ed.fi], 1);
            update3(distToS[ed.se.fi], -1);
            update2(distToS[ed.se.fi], 1);
            */
        }
    }
    //trace("aquiiii2");
    for(int i = 0; i < m; i++) {
        pair<int, ii> ed = edges[i];
       //trace("aquiiii");
        if (distToS[ed.fi] + distToT[ed.se.fi] + ed.se.se == distToS[t] && !hasIntersection(distToS[ed.fi], distToS[ed.se.fi])) {
            pr("YES\n");
        } else if (distToS[ed.fi] != INF && distToT[ed.se.fi] != INF && distToS[t] > distToS[ed.fi] + distToT[ed.se.fi] + 1) {
            pr("CAN %lld\n", distToS[ed.fi] + distToT[ed.se.fi] + ed.se.se - (distToS[t]-1));
        } else {
            pr("NO\n");
        }
    }
    return 0;
}