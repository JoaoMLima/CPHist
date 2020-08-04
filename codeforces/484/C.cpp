#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define MAX 1000007
#define MOD 1000000007
#define MODL 1000000007LL
#define sz(x) ((int)(x).size())
#define L(x) ((x)*2+1)
#define R(x) ((x)*2+2)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

// Trace dinâmico
template<typename T>
void trace(T a) { cout << a << "\n"; }
template<typename T, typename... Args>
void trace(T a, Args... args) { cout << a << " "; trace(args...); }

// Debugador de recursão
int recNum = 0;
void prTabs() { for (int ii = 0; ii < recNum; ++ii) cout << "    "; }
template<typename... Args>
void recInit(Args... args) { prTabs(); trace("rec(", args..., ")"); recNum++; }
template<typename T>
void recEnd(T a) { prTabs(); trace("->", a); recNum--;}

char s[MAX];
char t[MAX];
int nxt[MAX];
int vi[MAX];
int sequence[MAX];
int tmp[MAX];
int n, m, k, d;
int main(){
	int n = 0;
	char ch = getchar();
	while (ch != '\n') {
		s[n++] =ch;
		ch = getchar();
	}
	sc("%d", &m);
	for(int i = 0; i < m; i++) {
		sc("%d %d", &k, &d);
		for(int j = 0; j <= n; j++) {
			nxt[j] = j+1;
			vi[j] = 0;
		}
		int pos = -1;
		for(int j = 0; j < d; j++) {
			for(int x = 0; x+j < k; x += d) {
				if (pos >= 0) nxt[pos] = x+j;
				pos++;
			}
		}
		//for(int j = 0; j < n; j++) {
		//	trace(j, nxt[j]);
		//}
		int inic = 0;
		int j = 0;
		for(j = 0; j <= (n-k); j++) {
			sequence[j] = inic;
			//trace("set:", j, inic);
			vi[inic] = 1;
			inic = nxt[inic];
		}
		int ref = 0;
		//trace("aqui");
		while(1) {
			sequence[n-k+1+ref] = inic;
			//trace("set:", n-k+1+ref, inic);
			vi[inic] = 1; 
			if (inic == n-1)break;
			ref = nxt[ref];
			inic = nxt[inic];
		}
		//trace("aqui");
		for(int j = 0; j < n; j++) {
			if (!vi[j]) {
				int ciclo = 1;
				tmp[0] = j;
				inic = nxt[j];
				while(inic != j) {
					tmp[ciclo++] = inic;
					inic = nxt[inic];
				}
				//trace("ciclo: ", ciclo);
				//for(int z = 0; z < ciclo; z++) {
				//	cout << tmp[z] << " ";
				//}cout << endl;
				inic = tmp[(n-k+1)%ciclo];
				ref = j;
				for(int x = 0; x < ciclo; x++) {
					vi[inic] = 1;
					sequence[n-k+1+ref] = inic;
					//trace("set:", n-k+1+ref, inic);
					ref = nxt[ref];
					inic = nxt[inic];
				}
			}
		}
		for(int j = 0; j < n; j++) {
			t[j] = s[sequence[j]];
		}
		for(int j = 0; j < n; j++) {
			s[j] = t[j];
		}

		for(int j = 0; j < n; j++) {
			pr("%c", s[j]);
		}pr("\n");

	}
 	return 0;
}
