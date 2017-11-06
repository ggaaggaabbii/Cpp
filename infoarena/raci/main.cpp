#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 500010
ifstream f("raci.in");
ofstream g("raci.out");
vector<pair<int, int>> D[27];
struct {
  char a, b;
} v[MAXN];
int n, k, poz, nr, dp, maxim;
char a[11], x, y;
int main() {
  f >> n >> k;
  f.get();
  for (int i = 1; i <= n; i++) {
    f.get(a, 10, ' ');
    f.get();
    dp = 0;
    v[i].a = a[0];
    if (i != n)
      v[i].b = a[strlen(a) - 1];
    else
      v[i].b = a[strlen(a) - 2];
    poz = D[(int)(v[i].a - 'a')].size() - 1;
    while (poz >= 0 && i - D[(int)(v[i].a - 'a')][poz].second <= k) {
      dp = max(dp, D[(int)(v[i].a - 'a')][poz].first);
      poz--;
    }
    dp++;
    maxim = max(maxim, dp);
    poz = D[(int)(v[i].b - 'a')].size() - 1;
    while (poz >= 0 && D[(int)(v[i].b - 'a')][poz].first <= dp) {
      D[(int)(v[i].b - 'a')].pop_back();
      poz--;
    }
    D[(int)(v[i].b - 'a')].push_back(make_pair(dp, i));
  }
  g << maxim;
  return 0;
}
