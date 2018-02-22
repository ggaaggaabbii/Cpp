#include <bits/stdc++.h>
#define MAXN 100010
#define pb push_back

using namespace std;

ifstream f("ctc.in");
ofstream g("ctc.out");

vector<int> G[MAXN];
vector<vector<int>> sol;
stack<int> S;
int ind = 1, Index[MAXN], comp[MAXN];
bool onStack[MAXN];

void dfs(int node) {
	Index[node] = ind;
	comp[node] = ind;
	onStack[node] = true;
	S.push(node);
	++ind;
	for (auto it : G[node]) {
		if (!Index[it]) {
			dfs(it);
			comp[node] = min(comp[node], comp[it]);
		}
		else if (onStack[it]) {
			comp[node] = min(comp[node], Index[it]);
		}
	}
	if (Index[node] == comp[node]) {
		//new strongly connected component
		vector<int> v;
		int y;
		do {
			y = S.top();
			S.pop();
			onStack[y] = false;
			v.pb(y);
		} while (y != node);
		sol.pb(v);
	}
}

int main() {
	int n, m, x, y;
	f >> n >> m;
	while (m--) {
		f >> x >> y;
		G[x].pb(y);
	}
	for (int i = 1; i <= n; ++i) {
		onStack[i] = true;
	}
	for (int i = 1; i <= n; ++i) {
		if (Index[i] == 0) {
			dfs(i);
		}
	}
	g << sol.size() << '\n';
	for (auto it : sol) {
		for (auto it2 : it) {
			g << it2 << " ";
		}
		g << "\n";
	}
	return 0;
}