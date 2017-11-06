#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 100010
ifstream f("reinvent.in");
ofstream g("reinvent.out");
vector<int> G[MAXN];
queue<int> Q;
int n, m, k, x, y, viz[MAXN], dist[MAXN], tata[MAXN];
int distmin = 300000;
void bfs() {
  int nod;
  while (Q.size()) {
    nod = Q.front();
    Q.pop();
    viz[nod] = 1;
    for (auto it : G[nod]) {
      if (!viz[it]) {
        viz[it] = 1;
        dist[it] = dist[nod] + 1;
        tata[it] = tata[nod];
        Q.push(it);
      } else if (tata[nod] != tata[it])
        distmin = min(distmin, dist[it] + dist[nod] - 1);
    }
  }
}
int main() {
  f >> n >> m >> k;
  while (m--) {
    f >> x >> y;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 1; i <= k; i++) {
    f >> x;
    Q.push(x);
    tata[x] = x;
    dist[x] = 1;
  }
  bfs();
  g << distmin;
  return 0;
}
