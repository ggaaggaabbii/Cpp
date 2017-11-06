#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("ciurulet.in");
ofstream g("ciurulet.out");
char a[1000005], b[1000005];
int n, i, j, nr;
int main() {
  f >> n;
  f.get();
  f.getline(a + 2, n);
  strcpy(b + 2, a + 2);
  for (i = 2; i <= n; i++)
    if (a[i] == '1')
      for (j = 2 * i; j <= n; j += i) {
        if (a[j] == '1') {
          g << -1;
          return 0;
        }
        b[j] = '1';
      }
    else if (a[i] == '?' && b[i] != '1') {
      b[i] = '1';
      for (j = 2 * i; j <= n; j += i)
        if (a[j] == '1')
          b[i] = '0';

      if (b[i] == '1')
        for (j = 2 * i; j <= n; j += i)
          b[j] = '1';
    }

  for (i = 2; i <= n; i++)
    if (b[i] == '1')
      nr++;
  g << nr << '\n' << b + 2;
  return 0;
}
