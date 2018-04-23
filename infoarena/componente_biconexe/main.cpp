#include <bits/stdc++.h>
#define MAXN 100010

using namespace std;

ifstream f("biconex.in");
ofstream g("biconex.out");

vector<int> G[MAXN];
stack<pair<int, int> >s;
vector<vector<int> > solution;
int niv[MAXN], low[MAXN];
bool viz[MAXN];

void comp(int x, int y) {
    int a, b;
    solution.push_back(vector<int>());
    do {
        a = s.top().first;
        b = s.top().second;
        s.pop();
        solution.back().push_back(b);
    } while (a != x || b != y);
    solution.back().push_back(x);
}

void dfs(int node, int lvl) {
    niv[node] = low[node] = lvl;
    viz[node] = true;

    for (auto it:G[node]) {
        if (!viz[it]) {
            s.push({node, it});
            dfs(it, lvl + 1);
            low[node] = min(low[node], low[it]);
            if (low[it] >= niv[node])  // new biconex component found
            { comp(node, it); }
        } else {
            low[node] = min(low[node], niv[it]);
        }
    }
}

int main() {
    int n, m, x, y;
    f >> n >> m;

    while (m--) {
        f >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    for (int i = 0; i <= n; ++i) {
        viz[i] = false;
    }

    for (int i = 1; i <= n; ++i) {
        if (!viz[i]) {
            dfs(i, 0);
        }
    }

    g << solution.size() << "\n";

    for (auto it:solution) {
        for (auto it2:it) {
            g << it2 << " ";
        }
        g << "\n";
    }

    return 0;
}
