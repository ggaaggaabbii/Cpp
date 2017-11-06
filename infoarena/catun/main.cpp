#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
ifstream f("catun.in");
ofstream g("catun.out");
#define MAXN 36010
#define INF 1999000000
vector<pair<int, int>> G[MAXN];
queue<int> Q;
priority_queue<pair<int, int>> PQ;
int n, m, x, y, c, viz[MAXN], dist[MAXN], k, distmin[MAXN], tata[MAXN], nod,
    nod1;
pair<int, int> aux;
int main() {
  f >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    dist[i] = INF;
  while (k--) {
    f >> x;
    PQ.push(make_pair(0, x));
    dist[x] = 0;
    tata[x] = x;
  }
  while (m--) {
    f >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
    G[y].push_back(make_pair(x, c));
  }
  while (PQ.size()) {
    aux = PQ.top();
    PQ.pop();
    nod1 = aux.second;
    if (!viz[nod1]) {
      viz[nod1] = 1;
      for (int i = 0; i < G[nod1].size(); i++) {
        if (dist[nod1] + G[nod1][i].second < dist[G[nod1][i].first]) {
          dist[G[nod1][i].first] = dist[nod1] + G[nod1][i].second;
          PQ.push(make_pair(-dist[G[nod1][i].first], G[nod1][i].first));
          tata[G[nod1][i].first] = tata[nod1];
        } else {
          if (dist[nod1] + G[nod1][i].second == dist[G[nod1][i].first] &&
              tata[G[nod1][i].first] > tata[nod1])
            tata[G[nod1][i].first] = tata[nod1];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (tata[i] == i)
      tata[i] = 0;
    g << tata[i] << ' ';
  }
  return 0;
}
