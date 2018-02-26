#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define MAXN 100010
#define sec second
#define fir first
#define INF 100000000000000000

using namespace std;

vector<pair<int, int> > G[MAXN];
long long dp[MAXN], n, m, dad[MAXN];
priority_queue<pair<int, int> >Q;
bitset<MAXN> viz;

void go() {
	pair<int, int> aux;
	int node;
	dp[1] = 0;
	Q.push(mp(0, 1));
	while (!Q.empty()) {
		aux = Q.top();
		Q.pop();
		node = aux.sec;
		if (viz[node]) continue;
		for (auto it : G[node]) {
			if (dp[it.fir] > dp[node] + it.sec) {
				dad[it.fir] = node;
				dp[it.fir] = dp[node] + it.sec;
				Q.push(mp(-dp[it.fir], it.fir));
			}
		}
	}
}

void show(int node) {
	if (dad[node] == 0) {
		if (node != 1) {
			cout << "-1\n";
			exit(0);
		}
		else {
			cout << "1 ";
			return;
		}
	}
	show(dad[node]);
	cout << node << " ";
}

int main() {
	int x, y, c;
	cin >> n >> m;
	while (m--) {
		cin >> x >> y >> c;
		G[x].pb(mp(y, c));
		G[y].pb(mp(x, c));
	}
	for (int i = 0; i <= n; ++i)
		dp[i] = INF;
	go();
	show(n);
	cout << "\n";
	return 0;
}