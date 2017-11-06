#include <fstream>
#include <iostream>
using namespace std;
#define MAXN 110
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int a[MAXN][MAXN], n;
int main() {
  f >> n;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      f >> a[i][j];
    }
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (i != j && k != i && k != j)
          if (a[i][k] && a[k][j])
            if (a[i][j] == 0)
              a[i][j] = a[i][k] + a[k][j];
            else
              a[i][j] = min(a[i][j], a[i][k] + a[k][j]);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      g << a[i][j] << ' ';
    g << '\n';
  }
  return 0;
}
