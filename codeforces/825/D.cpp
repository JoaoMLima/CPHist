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
int n = 0, m, a, b, c;
//vector<int> g[maxn]; 
int cs[26];
int ct[26];
char s[1000000];
int main(){
	char ch = getchar();
    while(ch != '\n') {
        s[n++]= ch;
        if(ch != '?') {
            cs[ch-'a']++;
        }
        ch = getchar();
    }
    ch = getchar();
    while(ch != '\n') {
        ct[ch-'a']++;
        ch = getchar();
    }/*
    for(int i = 0; i < 26; i++) {
        trace((char)('a'+i), cs[i]);
    }
    for(int i = 0; i < 26; i++) {
        trace((char)('a'+i), ct[i]);
    }*/
    int maxi = 1000001;
    for(int i = 0; i < 26; i++) {
        if(ct[i] != 0) {

            maxi = min(maxi, cs[i]/ct[i]);
        }
    }
    //trace("maxi", maxi);

    for(int i = 0; i < 26; i++) {
        cs[i] -= ct[i]*maxi;
    }
    for(int i = 0; i < n; i++) {
        if (s[i] == '?') {
            //trace("s ",s[i]);
            for(int j = 0; j < 26; j++) {
                //trace(j,"cs",cs[j],"ct",ct[j]);
                if(cs[j] < ct[j]) {
                    //trace("aumentou");
                    cs[j]++;
                    s[i] = j+'a';break;
                } else if (j == 25) {
                    for(int k = 0; k < 26; k++) {
                        cs[k] -= ct[k];
                    }
                    for(int k = 0; k < 26; k++) {
                        if(cs[k] < ct[k]) {
                            cs[k]++;
                            s[i] = k+'a';
                            break;
                        }
                    }

                }
            }
        }putchar(s[i]);
    }
    putchar('\n');
 	return 0;
}