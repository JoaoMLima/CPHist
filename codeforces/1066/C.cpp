#include <bits/stdc++.h>
using namespace std;
#define printArr(harry, tam) range(tam) cout << harry[i] << " \n"[i == tam -1];
#define range(n) for(int i = 0; i < n; i++)
#define maxn 100000
#define mod 1000000007
#define md(x) (x) % mod
#define sc scanf
#define pr printf
#define getc getchar
#define putc putchar
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
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<double> vd;

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
char ch;
//vector<int> g[maxn];
int bit[1000000];
int query(int i) {
    int s = 0;
    for (; i; i -= (i & -i))
        s += bit[i];
    return s;
}
int query(int a, int b) {
    return query(b) - query(a - 1);
}
void update(int i) {
    for(;i < 1000000; i += (i & -i))
        bit[i]++;
}
int li[200001];
int main(){
    memset(li, 0, sizeof li);
    memset(bit, 0, sizeof bit);
    int menor = 500000;
    int maior = 500000;
    sc("%d\n", &n);
    for (int i = 0; i < n; i++) {
        sc("%c %d\n", &ch, &a);
        //trace(ch, a);
        if (ch == 'L') {
            menor--;
            li[a] = menor;
            update(menor);
        } else if (ch == 'R') {
            maior++;
            li[a] = maior;
            update(maior);
        } else {
            pr("%d\n", min(query(1, li[a]-1), query(li[a]+1, 1000000-1)));
        }
    }
    
	/*
	//Entrada 1
    while ((ch = getc()) != '\n') {
      s[n++] = ch;
    }
	//Entrada 2
    sc("%d\n", &n);
    for (int i = 0; i < n; i++) {
        sc("%d", li+i);
    }
	//Entrada 3
    sc("%s", &s);
	//Entrada 4
    while(sc("%d\n", &n) != EOF){

    }*/
 	return 0;
}
