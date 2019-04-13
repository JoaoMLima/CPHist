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
int n, m,h,  a, b, c;
int frontV[100];
int leftV[100];
int satisfLeft[100];
int satisfFront[100];
int topV[100][100];
int topV2[100][100];
vector<ii> frontVe;

int main(){
	memset(topV2, 0, sizeof topV2);
	memset(satisfLeft, 0, sizeof satisfLeft);
	memset(satisfFront, 0, sizeof satisfFront);
	sc("%d %d %d", &n, &m, &h);
	for(int i = 0; i < m; i++) {
		sc("%d", frontV+i);
		frontVe.pb({frontV[i], i});
	}
	for(int i = 0; i < n; i++) {
		sc("%d", leftV+i);
	}
	for(int i = 0; i < n*m; i++) {
		sc("%d", &a);// corrigir
		topV[i/m][i % m] = a;
	}
	sort(frontVe.begin(), frontVe.end());
	for(int i = m-1; i >= 0; i--) {
		int col = frontVe[i].se;
		int val = frontVe[i].fi;
		//trace("a", col, val);
		for(int j = 0; j < n; j++) {
			if (topV[j][col] && leftV[j] >= val) {
				topV2[j][col] = val;
				//trace("b", j, col, val);
				satisfFront[col]++; 
				if (leftV[j] == val) {
					satisfLeft[j] = 1; 
				}
			}
		}
	}
	for(int j = 0; j < n; j++) {
		if (!satisfLeft[j]) {
			for(int i = 0; i < m; i++) {
				if(topV[j][i] && frontV[i] >= leftV[j] && !topV2[j][i]) {
					topV2[j][i] = leftV[j];break;
				} else if (topV[j][i] && frontV[i] >= leftV[j] && satisfFront[i] > 1) {
					topV2[j][i] = leftV[j];
					satisfFront[i]--;break;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if (topV[i][j] && !topV2[i][j]) {
				pr("%d ", 1);
			} else {
				pr("%d ", topV2[i][j]);
			}

		}
		pr("\n");
	}

 	return 0;
}
