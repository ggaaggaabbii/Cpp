#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 100010
using namespace std;
ifstream f("aiacupalindroame.in");
ofstream g("aiacupalindroame.out");
int v[MAXN], n, m, ind[MAXN], k, x, y, viz[MAXN];
char c[MAXN];
vector<pair<int, int>> G[MAXN];
struct trie {
  int inod;
  trie *next[27];
  trie *ant;
  trie() {
    ant = 0;
    inod = 0;
    memset(next, 0, sizeof(next));
  }
} * q;
void dfs(int nod) {
  ind[nod] = q->inod;
  for (auto it : G[nod]) {
    if (q->next[it.second] == 0) {
      q->next[it.second] = new trie;
      q->next[it.second]->ant = q;
      q->next[it.second]->inod = ++k;
    }
    q = q->next[it.second];
    dfs(it.first);
  }
  q = q->ant;
}
int main() {
  f >> n >> m;
  for (int i = 2; i <= n; ++i)
    f >> v[i];
  for (int i = 2; i <= n; ++i)
    f >> c[i];
  for (int i = 2; i <= n; ++i)
    G[v[i]].push_back(make_pair(i, c[i] - 'a' + 1));
  q = new trie;
  dfs(1);
  while (m--) {
    f >> x >> y;
    if (ind[x] == ind[y])
      g << 1 << '\n';
    else
      g << 0 << '\n';
  }
  return 0;
}
