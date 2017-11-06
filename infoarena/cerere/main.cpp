#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
vector<int> G[MAXN];
int v[MAXN], tata[MAXN], n, x, y, viz[MAXN], ordins[MAXN], k;
ifstream f("cerere.in");
ofstream g("cerere.out");
void df(int nod) {
  viz[++k] = nod;
  if (ordins[nod])
    v[nod] = v[viz[k - ordins[nod]]] + 1;
  for (int i = 0; i < G[nod].size(); i++)
    df(G[nod][i]);
  k--;
}
int main() {
  int stra;
  f >> n;
  for (int i = 1; i <= n; i++)
    f >> ordins[i];
  for (int i = 1; i < n; i++) {
    f >> x >> y;
    tata[y] = x;
    G[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (tata[i] == 0) {
      df(i);
      break;
    }
  }
  for (int i = 1; i <= n; i++)
    g << v[i] << ' ';
  return 0;
}
