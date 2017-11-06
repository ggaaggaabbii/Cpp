#include <fstream>
#include <iostream>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
#define MAXN 100010
int n, v[MAXN], poz[MAXN], tata[MAXN], maxim, j, x, sir[MAXN], sol[MAXN];
void afis(int nod) {
  if (nod == 0)
    return;
  afis(tata[nod]);
  g << v[nod] << ' ';
}
int main() {
  f >> n;
  for (int i = 1; i <= n; i++) {
    f >> v[i];
    j = 1;
    while (sir[j] < v[i] && j <= maxim)
      j++;
    sir[j] = v[i];
    poz[j] = i;
    tata[i] = poz[j - 1];
    if (j > maxim) {
      maxim = j;
    }
  }
  g << maxim << '\n';
  afis(poz[maxim]);
  return 0;
}
