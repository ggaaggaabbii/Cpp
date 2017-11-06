#include <fstream>
#include <iostream>
using namespace std;
#define INF 10000000000000000
#define MAXN 510
ifstream f("podm.in");
ofstream g("podm.out");
long long n, v[MAXN], a[MAXN][MAXN];
int main() {
  f >> n;
  for (int i = 0; i <= n; i++)
    f >> v[i];
  for (int i = 1; i < n; i++)
    a[i][i + 1] = v[i - 1] * v[i] * v[i + 1];
  for (int w = 2; w < n; w++) {
    for (int i = 1; i <= n - w; i++) {
      int j = i + w;
      a[i][j] = INF;
      for (int k = i; k < j; k++) {
        a[i][j] = min(a[i][j], a[i][k] + a[k + 1][j] + v[i - 1] * v[k] * v[j]);
      }
    }
  }
  g << a[1][n];
  return 0;
}
