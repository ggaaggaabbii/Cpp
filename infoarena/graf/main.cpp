#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 7510
ifstream f("graf.in");
ofstream g("graf.out");
vector<int> G[MAXN];
queue<int> Q;
priority_queue<int> PQ;
int n, dist[MAXN], X, Y, x, y, m, viz[MAXN], nr, val[MAXN], noduri, dx[MAXN],
    dy[MAXN], rezultat[MAXN], k, aux;
void bfs(int d[]) {
  int nod;
  while (Q.size()) {
    nod = Q.front();
    Q.pop();
    viz[nod] = 1;
    for (auto it : G[nod]) {
      if (!viz[it]) {
        Q.push(it);
        viz[it] = 1;
        d[it] = d[nod] + 1;
      }
    }
  }
}
int main() {
  f >> n >> m >> X >> Y;
  for (int i = 1; i <= m; i++) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  Q.push(X);
  dx[X] = 1;
  bfs(dx);
  for (int i = 1; i <= n; i++)
    viz[i] = 0;
  Q.push(Y);
  dy[Y] = 1;
  bfs(dy);
  for (int i = 1; i <= n; i++) {
    if (dx[i] + dy[i] == dx[Y] + 1) {
      dist[dx[i]]++;
      val[dx[i]] = i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (dist[i] == 1) {
      k++;
      PQ.push(-val[i]);
    }
  }
  g << k << '\n';
  while (PQ.size()) {
    aux = PQ.top();
    g << -aux << ' ';
    PQ.pop();
  }
  return 0;
}
