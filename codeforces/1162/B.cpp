#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) ((((x) % mod) + mod) % mod)
#define sc scanf
#define pr printf
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define prt(x) cout << (#x) << " is " << (x) << endl
#define EPS 1e-9
#define INF INT_MAX
#define INFd 1e9

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;

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
int n, m, a, b, c;
int li1[50][50];
int li2[50][50];

int main(){
	sc("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sc("%d", &a);
            li1[i][j] = a;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sc("%d", &a);
            li2[i][j] = a;
        }
    }
    int possible = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (i == 0) {
                int min2 = min(li1[i][j-1], li2[i][j-1]), max2 = max(li1[i][j-1], li2[i][j-1]);
                int min3 = min(li1[i][j], li2[i][j]), max3 = max(li1[i][j], li2[i][j]);
                if (!(min3 > min2 && max3 > max2)) {
                    possible = 0;
                }
            } else if (j == 0) {
                int min1 = min(li1[i-1][j], li2[i-1][j]), max1 = max(li1[i-1][j], li2[i-1][j]);
                int min3 = min(li1[i][j], li2[i][j]), max3 = max(li1[i][j], li2[i][j]);
                if (!(min3 > min1 && max3 > max1)) {
                    possible = 0;
                }
            } else {
                int min1 = min(li1[i-1][j], li2[i-1][j]), max1 = max(li1[i-1][j], li2[i-1][j]);
                int min2 = min(li1[i][j-1], li2[i][j-1]), max2 = max(li1[i][j-1], li2[i][j-1]);
                int min3 = min(li1[i][j], li2[i][j]), max3 = max(li1[i][j], li2[i][j]);
                if (!(min3 > min1 && min3 > min2 && max3 > max1 && max3 > max2)) {
                    possible = 0;
                }
            }
        }
    }
    if (possible) {
        pr("Possible\n");
    } else {
        pr("Impossible\n");
    }
 	return 0;
}
