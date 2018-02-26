#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define sec second
#define fir first
#define INF 1000000000
#define MAXN 100010

using namespace std;

int currentColor[MAXN], desiredColor[MAXN], dad[MAXN], counter;
vector <int> G[MAXN];

void dfs(int node) {
	//cout << node << " ";
	currentColor[node] = currentColor[dad[node]];
	if (currentColor[node] != desiredColor[node]) {
		currentColor[node] = desiredColor[node];
		++counter;
	}
	for (auto it : G[node]) {
		if (it != dad[node]) {
			dfs(it);
		}
	}
}

int main() {
	int n, x;
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		cin >> x;
		G[x].pb(i);
		G[i].pb(x);
		dad[i] = x;
	}

	for (int i = 1; i <= n; ++i) {
		cin >> desiredColor[i];
	}
	dfs(1);
	cout << counter << "\n";
	return 0;

}