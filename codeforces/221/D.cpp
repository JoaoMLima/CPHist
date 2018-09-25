#include <bits/stdc++.h>
#define maxn 132680
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
#define INF 100000000
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int q, a, b, c, d, fa, fb;
int n, k = 0, m, t;
int sq;
struct query{
  int l, r, id;
  query() {l = 0; r = 0; id = 0;}
  query(int L, int R, int Id) {l = L; r = R; id = Id;}
  bool operator < (query o){
    if (l / sq != o.l / sq) return l < o.l;
    return r < o.r;}
};

int li[100000];
int cnt[100000];
int li2[100000];
query qr[100000];
map<int, int> ma;
int resps[100000];
int main() {
    sc("%d %d \n", &n, &m);
    sq = ceil(sqrt(n));
    for(int i = 0; i < n; i++) {
      sc("%d", &li[i]);
      li2[i] = li[i];
    }
    sort(li2, li2+n);
    int ult =  0;
    int a = -1;
    for(int i = 0; i < n; i++) {
      if (li2[i] != ult) {
        ult = li2[i]; ma[li2[i]] = ++a;
      }
    }
    for(int i = 0; i < n; i++) {
      li2[i] = ma[li[i]];
    }
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < m; i++) {
      sc("%d %d\n", &a, &b);
      qr[i] = query(a-1, b-1, i);
    }
    sort(qr, qr+m);
    int l = 0;
    int r = -1;
    int resp = 0;
    for(int i = 0; i < m; i++) {
      int L = qr[i].l;
      int R = qr[i].r;
      //pr("l: %d r: %d L: %d R: %d\n", l, r, L, R);
      while(r < R) {
        int mapped = li2[++r];
        
        cnt[mapped]++;
        if (cnt[mapped] == li[r]) {resp++;}
        if (cnt[mapped] == li[r]+1) {resp--;}
        //pr("r: %d mapped: %d cnt[mapped]: %d li[r]: %d resp: %d\n", r+1, mapped, cnt[mapped], li[r], resp);
      }
      while(r > R) {
        int mapped = li2[r];
        cnt[mapped]--;
        if (cnt[mapped] == li[r]) {resp++;}
        if (cnt[mapped] == li[r]-1) {resp--;}
        //pr("r: %d mapped: %d cnt[mapped]: %d li[r]: %d resp: %d\n", r, mapped, cnt[mapped], li[r], resp);
        r--;
      }
      while(l > L) {
        int mapped = li2[--l];
        //pr("l: %d mapped: %d\n", l-1, li2[l-1]);
        cnt[mapped]++;
        if (cnt[mapped] == li[l]) {resp++;}
        if (cnt[mapped] == li[l]+1) {resp--;}
      }
      while(l < L) {
        int mapped = li2[l];
        //pr("l: %d mapped: %d\n", l, li2[l]);
        cnt[mapped]--;
        if (cnt[mapped] == li[l]) {resp++;}
        if (cnt[mapped] == li[l]-1) {resp--;}
        l++;
      }
      //pr("r: %d\n", resp);
      resps[qr[i].id] = resp;
    }
    for(int i = 0; i < m; i++) {
      pr("%d\n", resps[i]);
    }
    return 0;
}
