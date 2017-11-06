#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 50010
#define INF 1000000000
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
vector<pair<int, int>> G[MAXN];
pair<int, int> aux;
priority_queue<pair<int, int>> PQ;
int viz[MAXN], dist[MAXN], n, m, x, y, c, nod;
int main() {
  f >> n >> m;
  for (int i = 1; i <= m; i++) {
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
    viz[nod]++;
    if (viz[nod] > m) {
      g << "Ciclu negativ!";
      return 0;
    }
    for (int i = 0; i < G[nod].size(); i++) {
      if (dist[nod] + G[nod][i].second < dist[G[nod][i].first]) {
        dist[G[nod][i].first] = dist[nod] + G[nod][i].second;
        PQ.push(make_pair(-dist[G[nod][i].first], G[nod][i].first));
      }
    }
  }
  for (int i = 2; i <= n; i++)
    g << dist[i] << ' ';
}
