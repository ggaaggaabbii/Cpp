#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 10010
#define MAXL 2010
#define maxb 100000
using namespace std;
ifstream f("ratina.in");
ofstream g("ratina.out");
char s[MAXN][MAXL];
vector<int> G[MAXN];
int k, n, m, v[30], mid, hi, lo, nr, minim, p, poz(maxb);
char buf[maxb];
int getint() {
  int nr = 0;
  while (buf[poz] < '0' || buf[poz] > '9')
    if (++poz >= maxb) {
      f.read(buf, maxb);
      poz = 0;
    }
  while (buf[poz] >= '0' && buf[poz] <= '9') {
    nr = nr * 10 + buf[poz] - '0';
    if (++poz >= maxb) {
      f.read(buf, maxb);
      poz = 0;
    }
  }
  return nr;
}
struct trie {
  int poz;
  trie *v[27];
  trie() {
    poz = 0;
    memset(v, 0, sizeof(v));
  }
} * Q;
void adaug(int poz) {
  trie *q = Q;
  int da;
  p = strlen(s[poz]);
  for (int i = 0; i < p; ++i) {
    da = s[poz][i] - 'a' + 1;
    if (q->v[da] == 0) {
      q->v[da] = new trie;
      q->v[da]->poz = ++k;
    }
    q = q->v[da];
    G[poz].push_back(q->poz);
  }
}
int verific() {
  int ok = G[v[1]][mid];
  for (int i = 1; i <= nr; ++i)
    if (G[v[i]][mid] != ok)
      return 0;
  return 1;
}
int main() {
  f >> n >> m;
  f.get();
  Q = new trie;
  for (int i = 1; i <= n; ++i) {
    f.getline(s[i], MAXL);
    adaug(i);
  }
  for (int i = 1; i <= m; ++i) {
    nr = getint();
    minim = MAXL;
    for (int j = 1; j <= nr; ++j) {
      v[j] = getint();
      minim = min(minim, (int)G[v[j]].size());
    }
    hi = minim;
    lo = -1;
    mid = minim - 1;
    if (verific())
      g << hi << '\n';
    else {
      while (hi - lo > 1) {
        mid = (hi + lo) / 2;
        if (verific())
          lo = mid;
        else
          hi = mid;
      }
      mid = hi;
      if (hi == minim + 1 && !verific())
        g << '0' << '\n';
      else
        g << hi << '\n';
    }
  }
  return 0;
}
