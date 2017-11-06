#include <fstream>
#include <iostream>
using namespace std;
ifstream f("heapuri.in");
ofstream g("heapuri.out");
#define MAXN 200010
int h[MAXN], poz[MAXN], n, N, x, op, v[MAXN], nr;
void sch(int x, int y) {
  swap(h[x], h[y]);
  poz[h[x]] = x;
  poz[h[y]] = y;
}
void sift(int poz) {
  int nod = poz;
  if (2 * poz <= N && v[h[2 * poz]] < v[h[nod]])
    nod = 2 * poz;
  if (2 * poz + 1 <= N && v[h[2 * poz + 1]] < v[h[nod]])
    nod = 2 * poz + 1;
  if (nod != poz) {
    sch(nod, poz);
    sift(nod);
  }
}
void per(int k) {
  while (k > 1 && v[h[k]] < v[h[k / 2]]) {
    sch(k, k / 2);
    k = k / 2;
  }
}
void del(int poz) {
  sch(poz, N--);
  per(poz);
  sift(poz);
}
int main() {
  f >> n;
  for (int i = 1; i <= n; i++) {
    f >> op;
    if (op == 3)
      g << v[h[1]] << '\n';
    else if (op == 2) {
      f >> x;
      del(poz[x]);
    } else {
      f >> v[++nr];
      h[++N] = nr;
      poz[nr] = N;
      per(N);
    }
  }
  return 0;
}
