#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("hamilton.in");
ofstream g("hamilton.out");
#define MAXN 18
#define INF 1000000000
vector<pair<int, int>> G[MAXN + 2];
int a[(1 << MAXN) + 10][MAXN + 2], x, y, c, n, m;
int cost = INF;
int main() {
  f >> n >> m;
  while (m--) {
    f >> x >> y >> c;
    G[y].push_back(make_pair(x, c));
  }
  for (int i = 0; i < (1 << MAXN); i++)
    for (int j = 0; j < n; j++)
      a[i][j] = INF;
  a[1][0] = 0;
  for (int i = 3; i <= (1 << n) - 1; i += 2)
    for (int j = 1; j < n; j++)
      if (i & (1 << j))
        for (auto it : G[j])
          a[i][j] = min(a[i][j], a[i - (1 << j)][it.first] + it.second);
  for (auto it : G[0])
    cost = min(cost, a[(1 << n) - 1][it.first] + it.second);
  if (cost != INF)
    g << cost;
  else
    g << "Nu exista solutie";
  return 0;
}
