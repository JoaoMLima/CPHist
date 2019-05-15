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
//vector<int> g[maxn]; 
int resp1, resp2, resp3, resp4;
int main(){
	printf("? 1 2\n");fflush(stdout);
    scanf("%d", &resp1);
    printf("? 2 3\n");fflush(stdout);
    scanf("%d", &resp2);
    printf("? 3 4\n");fflush(stdout);
    scanf("%d", &resp3);
    printf("? 4 5\n");fflush(stdout);
    scanf("%d", &resp4);
    
    int res[6] = {0,0,0,0,0,0};

    int li[6] = {4, 8, 15, 16, 23, 42};
    for(int i = 0; i < 6; i++) {
        for(int j = i+1; j < 6; j++) {
            if (li[i]*li[j] == resp1) {
                for(int k = 0; k < 6; k++) {
                    if (k != i && k != j && (li[i]*li[k] == resp2 || li[j]*li[k] == resp2)){
                        if (li[i]*li[k] == resp2){res[0] = li[j];}
                        else  {res[0] =li[i];}
                        break;
                    }
                }
                break;
            }
        }
    }
    //trace("AAAA");
    //trace(res[0], res[1]);
    res[1] = resp1 / res[0];
    //trace(res[1], res[2]);
    res[2] = resp2 / res[1];
    //trace(res[2], res[3]);
    res[3] = resp3 / res[2];
    //trace(res[3], res[4]);
    res[4] = resp4 / res[3];
    for(int i = 0; i < 6; i++) {
        if (li[i] != res[0] && li[i] != res[1] && li[i] != res[2] && li[i] != res[3] && li[i] != res[4]) {
            res[5] = li[i];
        }
    }
    printf("! %d %d %d %d %d %d\n", res[0], res[1], res[2], res[3], res[4], res[5]);
    fflush(stdout);
    return 0;
}
