#include <fstream>
#include <iostream>
using namespace std;
ifstream f("sortare2.in");
ofstream g("sortare2.out");
#define MAXN 100010
int poz[MAXN], nr, x, n;
int main() {
  f >> n;
  for (int i = 1; i <= n; ++i) {
    f >> x;
    poz[x] = i;
  }
  for (int i = 2; i <= n; i++) {
    if (poz[i] < poz[i - 1])
      nr++;
  }
  g << nr;
  return 0;
}
