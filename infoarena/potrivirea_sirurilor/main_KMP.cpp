#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
#define MAXN 2000010
char a[MAXN], b[MAXN];
int v[MAXN];
int n, m, p[MAXN], nr;
void build() {
  int k = 0;
  for (int i = 2; i <= n; i++) {
    while (k > 0 && a[i] != a[k + 1])
      k = p[k];
    if (a[i] == a[k + 1])
      ++k;
    p[i] = k;
  }
}
int main() {
  int k = 0;
  f.getline(a + 1, MAXN - 1);
  f.getline(b + 1, MAXN - 1);
  a[0] = 'a';
  b[0] = 'a';
  n = strlen(a) - 1;
  m = strlen(b) - 1;
  build();
  for (int i = 1; i <= m; i++) {
    while (k > 0 && a[k + 1] != b[i])
      k = p[k];
    if (a[k + 1] == b[i])
      ++k;
    if (k == n) {
      ++nr;
      if (nr <= 1000)
        v[nr] = i - k;
      k = p[k];
    }
  }
  g << nr << '\n';
  for (int i = 1; i <= nr && i <= 1000; i++)
    g << v[i] << ' ';
  return 0;
}
