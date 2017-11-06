#include <bitset>
#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 3005
#define INF 0x3f3f3f3f
ifstream f("carte.in");
ofstream g("carte.out");
bitset<MAXN> mat[MAXN];
char a[MAXN], b[MAXN];
int dp[MAXN], N, M, t, n, p[MAXN];
void prefix() {
  int k = 0;
  for (int i = 2; i <= M; ++i) {
    while (k > 0 && b[i] != b[k + 1])
      k = p[k];
    if (b[i] == b[k + 1])
      k++;
    p[i] = k;
  }
}
void solve() {
  int k = 0;
  for (int i = 1; i <= N; ++i) {
    while (k > 0 && a[i] != b[k + 1])
      k = p[k];
    if (a[i] == b[k + 1])
      k++;
    if (k == M) {
      mat[i - k + 1][i] = 1;
      k = p[k];
    }
  }
}
int main() {
  f >> t;
  f.get();
  a[0] = 'a';
  b[0] = 'a';
  while (t--) {
    f.getline(a + 1, MAXN);
    N = strlen(a) - 1;
    f >> n;
    f.get();
    while (n--) {
      f.getline(b + 1, MAXN);
      M = strlen(b) - 1;
      prefix();
      solve();
    }
    memset(dp, INF, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i <= N; ++i) {
      dp[i] = min(dp[i - 1] + 1, dp[i]);
      for (int j = 1; j <= i; ++j) {
        if (mat[j][i] == 1)
          dp[i] = min(dp[i], dp[j - 1]);
      }
    }
    g << dp[N] << '\n';
    for (int i = 1; i <= N; i++)
      mat[i].reset();
  }
  return 0;
}
