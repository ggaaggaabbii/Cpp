#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100010
#define MAXVAL 22;
ifstream f("coins.in");
ofstream g("coins.out");
int a[(1 << 22) + 10], s, n, nr, x;
int rez;
int val(int stare) {
  if (a[stare] != -1)
    return a[stare];
  if ((stare & (stare + 1)) == 0) {
    a[stare] = 1;
    return 1;
  }
  int zero = -1, aux;
  for (int i = 0; i < 22; i++) {
    if ((stare & (1 << i)) == 0)
      zero = i;
    else if (zero != -1) {
      aux = (stare - (1 << i) + (1 << zero));
      if (val(aux) == 0) {
        a[stare] = 1;
        return 1;
      }
    }
  }
  a[stare] = 0;
  return 0;
}
int main() {
  f >> n;
  for (int i = 0; i < (1 << 22); i++)
    a[i] = -1;
  for (int i = 1; i <= n; i++) {
    s = 0;
    nr = 0;
    for (int j = 0; j < 22; j++) {
      f >> x;
      if (x == 1) {
        s += (1 << j);
        nr++;
      }
    }
    if (val(s))
      rez += nr;
  }
  g << rez;
  return 0;
}
