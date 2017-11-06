#include <fstream>
#include <iostream>
using namespace std;
#define MOD 1999999973
ifstream f("lgput.in");
ofstream g("lgput.out");
long long putere(long long a, long long nr) {
  if (nr == 0)
    return 1;
  long long c = putere(a, nr / 2);
  c *= c;
  c %= MOD;
  if (nr % 2 == 0)
    return c % MOD;
  return (c * a) % MOD;
}
long long a, n;
int main() {
  f >> a >> n;
  g << putere(a, n);
  return 0;
}
