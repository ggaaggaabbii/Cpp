#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#define MAXN 100010
using namespace std;
ifstream f("xormax.in");
ofstream g("xormax.out");
int v[MAXN], n, w[22], l, r, maxim = -1;
struct trie {
  int poz;
  trie *v[2];
  trie() {
    poz = 0;
    memset(v, 0, sizeof(v));
  }
} * Q;
void query(int poz) {
  int aux = v[poz], sum = 0;
  memset(w, 0, sizeof(w));
  for (int i = 21; i >= 0; --i) {
    w[i] = (aux & 1);
    aux >>= 1;
  }
  trie *q = Q;
  for (int i = 0; i <= 21; ++i) {
    if (q->v[(w[i] ^ 1)] != 0) {
      sum += (1 << (21 - i));
      q = q->v[(w[i] ^ 1)];
    } else
      q = q->v[w[i]];
  }
  if (sum > maxim) {
    maxim = sum;
    l = q->poz + 1;
    r = poz;
    if (l == 0)
      l = 1;
    if (r == 0)
      r = 1;
    if (r < l)
      r = l;
  }
}
void update(int poz) {
  memset(w, 0, sizeof(w));
  int aux = v[poz];
  for (int i = 21; i >= 0; --i) {
    w[i] = (aux & 1);
    aux >>= 1;
  }
  trie *q = Q;
  for (int i = 0; i <= 21; ++i) {
    if (q->v[w[i]] == 0)
      q->v[w[i]] = new trie;
    q = q->v[w[i]];
  }
  q->poz = poz;
}
int main() {
  f >> n;
  Q = new trie;
  update(0);
  for (int i = 1; i <= n; ++i) {
    f >> v[i];
    v[i] = v[i] ^ v[i - 1];
    query(i);
    update(i);
  }
  g << maxim << ' ' << l << ' ' << r;
  return 0;
}
