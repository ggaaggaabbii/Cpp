#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 810
#define INF 1000000000
ifstream f("dragoni.in");
ofstream g("dragoni.out");
vector<pair<int, int>> G[MAXN];
queue<pair<int, int>> PQ;
pair<int, int> aux;
int viz[MAXN], p, n, m, x, c, y, dmax[MAXN], d[MAXN][MAXN], nod, drag, minim,
    dist;
int solve1(int nod, int val) {
  viz[nod] = 1;
  for (auto y : G[nod]) {
    int x = y.first;
    if (!viz[x] && y.second <= dmax[1]) {
      val = max(val, dmax[x]);
      val = max(val, solve1(x, val));
    }
  }
  return val;
}
int main() {
  f >> p;
  f >> n >> m;
  for (int i = 1; i <= n; i++)
    f >> dmax[i];
  for (int i = 1; i <= m; i++) {
    f >> x >> y >> c;
    G[x].push_back(make_pair(y, c));
    G[y].push_back(make_pair(x, c));
  }
  if (p == 1)
    g << solve1(1, dmax[1]);
  else {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        d[i][j] = INF;
    d[1][1] = 0;
    PQ.push(make_pair(1, 1));
    while (PQ.size()) {
      aux = PQ.front();
      PQ.pop();
      nod = aux.second;
      dist = d[nod][aux.first];
      if (dmax[nod] > dmax[aux.first])
        drag = nod;
      else
        drag = aux.first;
      for (auto y : G[nod]) {
        if (y.second <= dmax[drag] && dist + y.second < d[y.first][drag]) {
          d[y.first][drag] = dist + y.second;
          PQ.push(make_pair(drag, y.first));
        }
      }
    }
    minim = INF;
    /*for(int i=1;i<=n;i++)
        {
        for(int j=1;j<=n;j++)
        cout<<d[i][j]<<' ';
        cout<<endl;
        }*/
    for (int i = 1; i <= n; i++)
      minim = min(minim, d[n][i]);
    g << minim;
  }
  return 0;
}
