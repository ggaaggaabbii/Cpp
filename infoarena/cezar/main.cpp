#include <cstdio>
#include <vector>
using namespace std;
FILE *f, *g;
#define MAXN 10001
#define INF 1000000000
vector<short> G[MAXN];
short nod, vecin, h[MAXN], nr, p, j, ii, i;
int n, x, y, k;
void sterg(short a, short b) {
  for (i = 0; i < G[a].size(); i++)
    if (G[a][i] == b) {
      swap(G[a][i], G[a][G[a].size() - 1]);
      G[a].pop_back();
      return;
    }
}
int main() {
  f = fopen("cezar.in", "r");
  g = fopen("cezar.out", "w");
  int cost[MAXN], s = 0;
  fscanf(f, "%d%d", &n, &k);
  for (short i = 1; i < n; i++) {
    fscanf(f, "%d%d", &x, &y);
    G[x].push_back(y);
    G[y].push_back(x);
    cost[i] = 1;
  }
  cost[n] = 1;
  cost[n + 1] = INF;
  h[n + 1] = INF;
  for (short i = 1; i <= n; i++)
    if (G[i].size() == 1)
      h[++nr] = i;
  for (ii = n; ii > k + 1; ii--) {
    nod = h[1];
    s += cost[nod];
    vecin = G[nod][0];
    G[nod].pop_back();
    sterg(vecin, nod);
    sterg(nod, vecin);
    cost[vecin] += cost[nod];
    if (G[vecin].size() == 1)
      h[1] = vecin;
    else {
      swap(h[1], h[nr--]);
      h[nr + 1] = n + 1;
    }
    j = 1;
    while (2 * j <= nr) {
      if (2 * j + 1 <= nr && cost[h[2 * j]] > cost[h[2 * j + 1]])
        p = 2 * j + 1;
      else
        p = 2 * j;
      if (cost[h[j]] > cost[h[p]]) {
        swap(h[j], h[p]);
        j = p;
      } else
        j = n + 1;
    }
  }
  fprintf(g, "%d\n", s);
  fclose(f);
  fclose(g);
  return 0;
}
