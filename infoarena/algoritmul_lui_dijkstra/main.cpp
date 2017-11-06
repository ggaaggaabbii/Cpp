#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 50010
#define INF 1000000000
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
vector<pair<int, int>> G[MAXN];
priority_queue<pair<int, int>> PQ;
int n, m, x, y, c, dist[MAXN], viz[MAXN], nod;
pair<int, int> aux;
int main() {
  f >> n >> m;
  while (m--) {
    f >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
  }
  for (int i = 2; i <= n; i++)
    dist[i] = INF;
  dist[1] = 0;
  PQ.push(make_pair(0, 1));
  while (PQ.size()) {
    aux = PQ.top();
    PQ.pop();
    nod = aux.second;
    if (!viz[nod]) {
      viz[nod]++;
      for (int i = 0; i < G[nod].size(); i++) {
        if (dist[nod] + G[nod][i].second < dist[G[nod][i].first]) {
          dist[G[nod][i].first] = dist[nod] + G[nod][i].second;
          PQ.push(make_pair(-dist[G[nod][i].first], G[nod][i].first));
        }
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (dist[i] == INF)
      dist[i] = 0;
    g << dist[i] << ' ';
  }
  return 0;
}
