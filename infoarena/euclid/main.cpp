#include <fstream>
#include <iostream>
#define MAXN 410
#define MAXLG 10
using namespace std;
ifstream f("euclid.in");
ofstream g("euclid.out");
int rmq[MAXLG][MAXN], lg[MAXN], t, n, m, h, w, k1, k2, maxim, aux, pow1, pow2,
    k, ans;
int cmmdc(int a, int b) {
  int r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
void buildl(int *b) {
  for (int i = 1; i <= m; i++)
    f >> rmq[0][i];
  for (int k = 1; k <= lg[m]; k++)
    for (int i = 1; i + (1 << (k - 1)) <= m; i++)
      rmq[k][i] = cmmdc(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
  for (int i = 1; i <= m - w + 1; i++)
    b[i] = cmmdc(rmq[lg[w]][i], rmq[lg[w]][i + w - (1 << lg[w])]);
}
int b[MAXN][MAXN];
void buildc(int poz) {
  for (int i = 1; i <= n; i++)
    rmq[0][i] = b[i][poz];
  for (int k = 1; k <= lg[n]; k++)
    for (int i = 1; i + (1 << (k - 1)) <= n; i++)
      rmq[k][i] = cmmdc(rmq[k - 1][i], rmq[k - 1][i + (1 << (k - 1))]);
  for (int i = 1; i <= n - h + 1; i++)
    ans = max(ans, cmmdc(rmq[lg[h]][i], rmq[lg[h]][i + h - (1 << lg[h])]));
}
int main() {
  f >> t;
  for (int i = 2; i < MAXN; i++)
    lg[i] = lg[i >> 1] + 1;
  for (int p = 1; p <= t; p++) {
    f >> n >> m >> h >> w;
    maxim = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
      buildl(b[i]);
    for (int i = 1; i <= m; i++) {
      buildc(i);
      maxim = max(maxim, ans);
    }
    g << "Case #" << p << ": " << maxim << '\n';
  }
  return 0;
}
