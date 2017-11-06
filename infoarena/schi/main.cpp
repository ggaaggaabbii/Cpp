#include <fstream>
#include <iostream>
using namespace std;
ifstream f("schi.in");
ofstream g("schi.out");
int v[200000], b, n, w[30010], a, poz[30010];
void update(int nod, int l, int r) {
  if (l == r) {
    v[nod] = b;
    return;
  }
  int mij = (l + r) / 2;
  if (a <= mij) {
    update(2 * nod, l, mij);
  } else {
    update(2 * nod + 1, mij + 1, r);
  }
  v[nod] = v[2 * nod] + v[2 * nod + 1];
}
int query(int nod, int l, int r, int sum) {
  if (l == r) {
    return l;
  }
  int mij = (l + r) / 2;
  if (sum <= v[2 * nod]) {
    return query(2 * nod, l, mij, sum);
  } else {
    return query(2 * nod + 1, mij + 1, r, sum - v[2 * nod]);
  }
}
int main() {
  f >> n;
  b = 1;
  for (a = 1; a <= n; a++) {
    f >> w[a];
    update(1, 1, n);
  }
  b = 0;
  for (int i = n; i >= 1; i--) {
    a = query(1, 1, n, w[i]);
    update(1, 1, n);
    poz[a] = i;
  }
  for (int i = 1; i <= n; i++)
    g << poz[i] << '\n';
  return 0;
}
