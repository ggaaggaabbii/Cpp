#include <fstream>
#include <iostream>
#include <string.h>
#define MAXN 110
#define MAXL 310
using namespace std;
ifstream f("sub.in");
ofstream g("sub.out");
int n, m, minim(MAXL), l[MAXN], pmin, rez, lm;
char a[MAXN][MAXL], b[MAXL];
struct trie {
  int v[101], ok;
  trie *nextnod[27];
  trie() {
    ok = 0;
    memset(v, 0, sizeof(v));
    memset(nextnod, 0, sizeof(nextnod));
  }
} * Q;
void ad(int poz) {
  for (int i = 0; i < l[poz]; ++i) {
    trie *q = Q;
    for (int j = i; j < l[poz]; ++j) {
      if (q->nextnod[a[poz][j] - 'a' + 1] == 0)
        q->nextnod[a[poz][j] - 'a' + 1] = new trie;
      q = q->nextnod[a[poz][j] - 'a' + 1];
      if (q->v[poz] == 0) {
        q->v[poz] = 1;
        q->v[0]++;
      }
    }
  }
}
void adauga(int poz) {
  for (int i = 0; i < l[poz]; ++i) {
    trie *q = Q;
    for (int j = i; j < l[poz]; ++j) {
      if (q->nextnod[a[poz][j] - 'a' + 1] == 0 ||
          q->nextnod[a[poz][j] - 'a' + 1]->v[0] < poz - 1)
        break;
      q = q->nextnod[a[poz][j] - 'a' + 1];
      if (q->v[poz] == 0) {
        q->v[poz] = 1;
        q->v[0]++;
        if (q->v[0] == n) {
          q->ok = 1;
          ++rez;
        }
      }
    }
  }
}
void adaugb() {
  for (int i = 0; i < lm; ++i) {
    trie *q = Q;
    for (int j = i; j < lm; ++j) {
      if (q->nextnod[b[j] - 'a' + 1] == 0)
        break;
      if (q->nextnod[b[j] - 'a' + 1]->ok == 1) {
        q->nextnod[b[j] - 'a' + 1]->ok = 0;
        --rez;
      }
      q = q->nextnod[b[j] - 'a' + 1];
    }
  }
}
int main() {
  f >> n;
  f.get();
  Q = new trie;
  for (int i = 1; i <= n; ++i) {
    f.getline(a[i], MAXL);
    l[i] = strlen(a[i]);
    if (l[i] < minim) {
      minim = min(minim, l[i]);
      pmin = i;
    }
  }
  ad(pmin);
  for (int i = 1; i <= n; ++i)
    if (i != pmin)
      adauga(i);
  f >> m;
  f.get();
  while (m--) {

    f.getline(b, MAXL);
    lm = strlen(b);
    adaugb();
  }
  g << rez;
  return 0;
}
