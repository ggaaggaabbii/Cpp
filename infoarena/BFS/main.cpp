#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100010
vector<int> G[MAXN];
queue<int> Q;
int dist[MAXN], n, m, x, y, pct;
ifstream f("bfs.in");
ofstream g("bfs.out");
void bfs(int nod) {
  int aux;
  for (int i = 1; i <= n; i++)
    dist[i] = -1;
  dist[nod] = 0;
  Q.push(nod);
  while (Q.size()) {
    aux = Q.front();
    Q.pop();
    for (int i = 0; i < G[aux].size(); i++) {
      if (dist[G[aux][i]] == -1) {
        Q.push(G[aux][i]);
        dist[G[aux][i]] = dist[aux] + 1;
      }
    }
  }
}
int main() {
  f >> n >> m >> pct;
  while (m--) {
    f >> x >> y;
    G[x].push_back(y);
  }
  bfs(pct);
  for (int i = 1; i <= n; i++)
    g << dist[i] << ' ';
  return 0;
}
