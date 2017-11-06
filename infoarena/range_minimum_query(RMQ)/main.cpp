#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
#define MAXN 100010
#define MAXLOGN 20
int a[MAXN][MAXLOGN], n, m, v[MAXN], x, y, k;
int main() {
  f >> n >> m;
  for (int i = 0; i < n; i++)
    f >> v[i];
  for (int i = 0; i < n; i++)
    a[i][0] = i;
  for (int j = 1; 1 << j <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      if (v[a[i][j - 1]] <= v[a[i + (1 << (j - 1))][j - 1]])
        a[i][j] = a[i][j - 1];
      else
        a[i][j] = a[i + (1 << (j - 1))][j - 1];
    }
  }
  while (m--) {
    f >> x >> y;
    x--;
    y--;
    k = log2(y - x + 1);
    if (v[a[x][k]] < v[a[y - (1 << k) + 1][k]])
      g << v[a[x][k]] << '\n';
    else
      g << v[a[y - (1 << k) + 1][k]] << '\n';
  }
  return 0;
}
