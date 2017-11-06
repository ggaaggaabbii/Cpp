#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
#define MAXN 200010
ifstream f("calafat.in");
ofstream g("calafat.out");
long long aib[MAXN], v[MAXN], sol[MAXN], n, m, x, y, last[MAXN];
vector<pair<int, int>> q[MAXN];
pair<int, int> upd[MAXN];
void update(int poz, int val) {
  for (int i = poz; i <= n; i += i & (-i))
    aib[i] += val;
}
long long query(int poz) {
  long long sum = 0;
  for (int i = poz; i > 0; i -= i & (-i))
    sum += aib[i];
  return sum;
}
int main() {
  f >> n >> m;
  memset(upd, 0, sizeof(upd));
  for (int i = 1; i <= n; ++i) {
    f >> v[i];
    if (last[v[i]] == 0)
      last[v[i]] = i;
    else {
      upd[i] = make_pair(last[v[i]], i - last[v[i]]);
      last[v[i]] = i;
    }
  }
  for (int i = 1; i <= m; ++i) {
    f >> x >> y;
    q[y].push_back(make_pair(x, i));
  }
  for (int i = 1; i <= n; ++i) {
    if (upd[i].first)
      update(upd[i].first, upd[i].second);
    for (auto it : q[i])
      sol[it.second] = query(i) - query(it.first - 1);
  }
  for (int i = 1; i <= m; ++i)
    g << sol[i] << '\n';
  return 0;
}
