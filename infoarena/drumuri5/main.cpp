#include <bits/stdc++.h>
#include <cstring>
#define MAXN 150010
#define pb push_back

using namespace std;

ifstream f("drumuri5.in");
ofstream g("drumuri5.out");

int entry[MAXN], outer[MAXN], Index[MAXN], comp[MAXN], dad[MAXN], maxSize, ind, n, m, x, y, Count;
bitset<MAXN> viz;
vector<int> G[MAXN], nonCiclicG[MAXN], nonCiclicGRev[MAXN], topS;
vector<vector<int>> sol;
stack<int> S;
bool onStack[MAXN];

void conex(int node) {
	Index[node] = ind;
	comp[node] = ind;
	++ind;
	onStack[node] = true;
	S.push(node);
	for (auto it : G[node]) {
		if (!Index[it]) {
			conex(it);
			comp[node] = min(comp[node], comp[it]);
		}
		else if (onStack[it]) {
			comp[node] = min(comp[node], Index[it]);
		}
	}

	if (Index[node] == comp[node]) {
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

void buildNewGraph(int node) {
	viz[node] = 1;
	for (auto it : G[node]) {
		if (comp[it] != comp[node]) {
			//cout << node << " " << it << "\n";
			nonCiclicG[comp[node]].pb(comp[it]);
			nonCiclicGRev[comp[it]].pb(comp[node]);
		}
		if (!viz[it]) {
			buildNewGraph(it);
		}
	}
}

void topSort(vector<int> G[MAXN], int node) {
	viz[node] = 1;
	for (auto it : G[node]) {
		if (!viz[it]) {
			topSort(G, it);
		}
	}
	topS.pb(node);
}

void solve(vector<int> G[MAXN], int* val) {
	int node, aux;
	for (int i = 0; i < maxSize; ++i) {
		Index[topS[i]] = i;
	}

	for (int i = 0; i < maxSize; ++i) {
		node = topS[i];
		++val[node];
		aux = -1;
		for (auto it : G[node]) {
			if (aux == -1 || Index[it] < Index[aux]) {
				aux = it;
			}
		}
		if (aux != -1) {
			val[aux] += val[node];
		}
	}
}

void printSol() {
	vector<int> v;
	for (int i = 0; i < maxSize; ++i) {
		if (entry[i] + outer[i] == maxSize + 1)
			v.pb(i);
	}
	int c = 0;

	memset(dad, 0, sizeof(dad));
	for (auto it : v) {
		for (auto it2 : sol[it]) {
			dad[it2] = 1;
			++c;
		}
	}
	g << c << "\n";
	for (int i = 1; i <= n; ++i) {
		if (dad[i] == 1) {
			g << i << " ";
		}
	}
	g << "\n";
}

int main() {
	f >> n >> m;
	while (m--) {
		f >> x >> y;
		G[x].pb(y);
	}
	for (int i = 0; i <= n; ++i) {
		onStack[i] = false;
	}
	for (int i = 1; i <= n; ++i) {
		if (!Index[i]) {
			conex(i);
		}
	}
	for (int i = 0; i < sol.size(); ++i) {
		for (auto it : sol[i])
			comp[it] = i;
	}

	viz.reset();
	for (int i = 1; i <= n; ++i) {
		if (!viz[i])
			buildNewGraph(i);
	}
	maxSize = sol.size();

	Count = maxSize;
	viz.reset();
	for (int i = 0; i < maxSize; ++i) {
		if (!viz[i])
			topSort(nonCiclicG, i);
	}
	solve(nonCiclicGRev, entry);
	reverse(topS.begin(), topS.end());
	solve(nonCiclicG, outer);
	printSol();

	return 0;
}