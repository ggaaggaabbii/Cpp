#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 200010
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
vector<pair<int, int>> G[MAXN], v;
priority_queue<pair<int, pair<int, int>>> PQ;
int n, m, viz[MAXN], nr, s, x, y, c, cost, nod1, nod2;
int main() {
  f >> n >> m;
  while (m--) {
    f >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
    G[y].push_back(make_pair(x, c));
  }
  viz[0] = 1;
  PQ.push(make_pair(0, make_pair(0, 1)));
  while (nr < n) {
    cost = PQ.top().first;
    nod1 = PQ.top().second.first;
    nod2 = PQ.top().second.second;
    PQ.pop();
    if (!viz[nod1]) {
      s -= cost;
      v.push_back(make_pair(nod1, nod2));
      viz[nod1] = 1;
      for (auto it : G[nod1])
        if (!viz[it.first])
          PQ.push(make_pair(-it.second, make_pair(nod1, it.first)));
      ++nr;
    }
    if (!viz[nod2]) {
      s -= cost;
      v.push_back(make_pair(nod1, nod2));
      viz[nod2] = 1;
      for (auto it : G[nod2])
        if (!viz[it.first])
          PQ.push(make_pair(-it.second, make_pair(nod2, it.first)));
      ++nr;
    }
  }
  g << s << '\n' << n - 1 << '\n';
  for (int i = 1; i < v.size(); ++i)
    g << v[i].first << ' ' << v[i].second << '\n';
  return 0;
}
