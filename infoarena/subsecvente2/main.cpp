#include <fstream>
#include <iostream>
#include <string.h>
#define MAXN 50010
using namespace std;
ifstream f("subsecvente2.in");
ofstream g("subsecvente2.out");
char s[7][MAXN];
int v[7], n, minim = MAXN, dist, pozmin;
struct tri {
  int mask;
  tri *nexttri[2];
  tri() {
    mask = 0;
    nexttri[1] = nexttri[0] = 0;
  }
} * trie;
void adaug(int poz) {
  tri *q = trie;
  q->mask |= (1 << (pozmin - 1));
  for (int i = poz; i < min(v[pozmin], poz + 60); ++i) {
    if (q->nexttri[s[pozmin][i]] == 0)
      q->nexttri[s[pozmin][i]] = new tri;
    q = q->nexttri[s[pozmin][i]];
    q->mask |= (1 << (pozmin - 1));
  }
}
void ver(int sir, int poz) {
  tri *q = trie;
  q->mask |= (1 << (sir - 1));
  for (int i = poz; i < min(poz + 60, v[sir]); ++i) {
    if (q->nexttri[s[sir][i]] == 0)
      return;
    q = q->nexttri[s[sir][i]];
    q->mask |= (1 << (sir - 1));
    if (q->mask == (1 << n) - 1)
      dist = max(dist, i - poz + 1);
  }
}
int main() {
  trie = new tri;
  f >> n;
  f.get();
  for (int i = 1; i <= n; ++i) {
    f.getline(s[i], MAXN);
    v[i] = strlen(s[i]);
    for (int j = 0; j < v[i]; ++j)
      s[i][j] -= 'a';
    if (v[i] < minim) {
      minim = v[i];
      pozmin = i;
    }
  }
  for (int i = 0; i < v[pozmin]; ++i)
    adaug(i);
  for (int i = 1; i <= n; ++i)
    if (i != pozmin) {
      for (int j = 0; j < v[i]; ++j)
        ver(i, j);
    }
  g << dist;
  return 0;
}
