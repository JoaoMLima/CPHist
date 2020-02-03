#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define fi first
#define se second
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> ii;
int n;
ll a, b, c, p;
ll resp[100010];
ll tim[100010];
set<int> naFila;
queue<int> q;
priority_queue<int, vector<int>, greater<int> > ready;
priority_queue<ii, vector<ii>, greater<ii> > waiting;

int main(){
	sc("%d %lld", &n, &p);
	for(int i = 0; i < n; i++) {
		sc("%lld", tim+i);
		waiting.push({tim[i], i});
	}
	
	ll t = 0;
	ll nxt = 0;
	int emAtendimento = 1000000000;
	while(!waiting.empty() || !ready.empty() || !q.empty()) {
		if (nxt <= t) {emAtendimento = 1000000000;}
		while(!waiting.empty() && waiting.top().first <= t) {
			ready.push(waiting.top().second);
			waiting.pop();
		}
		if (!ready.empty() && (naFila.empty() || ready.top() < *naFila.begin()) && ready.top() < emAtendimento) {
			q.push(ready.top());
			naFila.insert(ready.top());
			ready.pop();
		}
		if (nxt <= t && !q.empty()) {
			resp[q.front()] = t+p;
			nxt = t+p;
			emAtendimento = q.front();
			naFila.erase(q.front());
			q.pop();
			t = nxt;
			if (!waiting.empty() && waiting.top().first < t) t = waiting.top().first;
		} else {
			if (nxt > t) {
				t = nxt;
				if (!waiting.empty() && waiting.top().first < t) t = waiting.top().first;
			} else {
				if (!waiting.empty()) t = waiting.top().first;
			}
			
		}
	}
	for(int i = 0; i < n; i++) {
		if (i) pr(" ");
		pr("%lld", resp[i]);
	}pr("\n");


 	return 0;
}
