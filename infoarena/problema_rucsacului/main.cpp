#include <fstream>
#include <iostream>
using namespace std;
#define MAXN 5010
#define MAXG 10010
ifstream f("rucsac.in");
ofstream g("rucsac.out");
int n, a[2][MAXG], val[MAXN], w[MAXN], gr, maxim, nr, nr1, i, j;
int main() {
  f >> n >> gr;
  for (i = 1; i <= n; i++) {
    f >> w[i] >> val[i];
    for (j = 0; j <= gr; j++) {
      a[i % 2][j] = a[(i - 1) % 2][j];
      if (j >= w[i])
        if (a[i % 2][j] < a[(i - 1) % 2][j - w[i]] + val[i]) {
          a[i % 2][j] = a[(i - 1) % 2][j - w[i]] + val[i];
        }
    }
  }
  g << a[n % 2][gr];
  return 0;
}
