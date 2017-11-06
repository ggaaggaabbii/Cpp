#include <fstream>
#include <iostream>
using namespace std;
#define ll long long
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
ll MOD, a;
ll putere(int a, int nr) {
  if (nr == 0)
    return 1;
  ll c = putere(a, nr / 2);
  c = (c * c) % MOD;
  if (nr % 2 == 0)
    return c;
  return (c * a) % MOD;
}
ll getphi(ll nr) {
  ll cur = nr;
  for (int i = 2; i * i <= nr; i++) {
    if (nr % i == 0) {
      while (nr % i == 0)
        nr /= i;
      cur = cur / i * (i - 1);
    }
  }
  if (nr != 1)
    return cur / nr * (nr - 1);
  return cur;
}
int main() {
  f >> a >> MOD;
  ll p = getphi(MOD) - 1;
  g << putere(a, p);
  return 0;
}
