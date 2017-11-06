#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 1000010
ifstream f("prefix.in");
ofstream g("prefix.out");
char a[MAXN];
int n, t, p[MAXN], ok;
void prefix() {
  int k = 0;
  p[1] = p[0] = 0;
  for (int i = 2; i <= n; ++i) {
    while (k > 0 && a[i] != a[k + 1])
      k = p[k];
    if (a[i] == a[k + 1])
      ++k;
    p[i] = k;
  }
}
int main() {
  f >> t;
  f.get();
  a[0] = 'a';
  while (t--) {
    f.getline(a + 1, MAXN);
    n = strlen(a) - 1;
    prefix();
    ok = 1;
    for (int i = n; i > 0; --i)
      if (i % (i - p[i]) == 0 && p[i]) {
        g << i << '\n';
        ok = 0;
        break;
      }
    if (ok == 1)
      g << 0 << '\n';
  }
  return 0;
}
