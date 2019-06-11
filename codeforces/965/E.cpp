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
char s[100010];

struct lengths{
    priority_queue<int> sizes = priority_queue<int>();
};
typedef lengths* pLengths;

struct Trie{
    map<char, Trie*> next;
    int size = 0;
    int terminal = 0;
    pLengths suffixes;
};
typedef Trie* pTrie;

void insertWord(pTrie trie, int i, int sz){
    trie->size++;
    //trace(s[i], i, sz, trie->size);
    if (i == sz)  {trie->terminal = 1; return;}

    if (!(trie->next.count(s[i]))) {trie->next[s[i]] = new Trie;}
    insertWord(trie->next[s[i]], i+1, sz);
}

void dfsTrie(pTrie root, int podeSubstituir, int tam) {
    //trace("aqui1", tam);
    root->suffixes = new lengths;
    int maxi = 0;
    char maxiChar = '0';
    //trace("aqui2");
    for (pair<char, Trie*> val : root->next) {
        //trace("aqui6");
        dfsTrie(val.se, 1, tam+1);
        //trace("aqui5");
        if (val.se->size > maxi) {
            maxi = val.se->size;
            maxiChar = val.fi;
            root->suffixes = val.se->suffixes;
        }
    }
    for (pair<char, Trie*> val : root->next) {
        if (val.fi != maxiChar) {
            while(!val.se->suffixes->sizes.empty()) {
                root->suffixes->sizes.push(val.se->suffixes->sizes.top());
                val.se->suffixes->sizes.pop();
            }
        }
    }
    //trace("aqui3");
    if (maxi != 0 && podeSubstituir && !root->terminal) {
        root->suffixes->sizes.pop(); root->suffixes->sizes.push(tam);
    } else {
        root->suffixes->sizes.push(tam);
    }
    //trace("aqui4");
}
Trie root = Trie();



int main(){
    int n;
	sc("%d\n", &n);
    for(int i = 0; i < n; i++){
        //trace("p1");
        char ch = getchar();
        int sz = 0;
        while(ch != '\n') {
            s[sz++] = ch;
            ch = getchar();
        }
        insertWord(&root, 0, sz);
    }
    
    dfsTrie(&root, 0, 0);
    
    int resp = 0;
    while(!root.suffixes->sizes.empty()) {
        resp += root.suffixes->sizes.top();
        root.suffixes->sizes.pop();
    }
    pr("%d\n", resp);
 	return 0;
}
