#include <bitset>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 1010
ifstream f("tastatura.in");
ofstream g("tastatura.out");
char a[MAXN], b[60];
bitset<MAXN> mat[MAXN];
int p[MAXN], dp[MAXN], n, m, N;
void prefix() {
  int k = 0;
  p[0] = p[1] = 0;
  for (int i = 2; i <= m; ++i) {
    while (k > 0 && b[i] != b[k + 1])
      k = p[k];
    if (b[i] == b[k + 1])
      ++k;
    p[i] = k;
  }
}
void solve() {
  int k = 0;
  for (int i = 1; i <= n; ++i) {
    while (k > 0 && a[i] != b[k + 1])
      k = p[k];
    if (a[i] == b[k + 1])
      ++k;
    if (k == m) {
      mat[i - k + 1][i] = 1;
      k = p[k];
    }
  }
}
int main() {
  a[0] = b[0] = 'a';
  f.getline(a + 1, MAXN);
  n = strlen(a) - 1;
  f >> N;
  f.get();
  while (N--) {
    f.getline(b + 1, 60);
    m = strlen(b) - 1;
    prefix();
    solve();
  }
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1] + 1;
    for (int j = 1; j <= i; ++j)
      if (mat[j][i])
        dp[i] = min(dp[i], dp[j - 1] + 1);
  }
  g << dp[n];
  return 0;
}
