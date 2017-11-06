#include <fstream>
#include <iostream>
#define MAXN 1000010
#define MOD 1000000007
using namespace std;
ifstream f("cabana.in");
ofstream g("cabana.out");
long long pw(long long a, long long nr) {
  if (nr == 0)
    return 1;
  long long c = pw(a, nr / 2);
  c *= c;
  c %= MOD;
  if (nr % 2 == 0)
    return c % MOD;
  return (c * a) % MOD;
}
int fact[MAXN];
long long inv, ans, t, n, k;
int main() {
  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = (1ll * i * fact[i - 1]) % MOD;
  f >> t;
  while (t--) {
    f >> n >> k;
    inv = pw(1ll * fact[k - n % k], 1ll * (MOD - 2));
    inv %= MOD;
    ans = pw(1ll * fact[k], 1ll * (n / k + 1));
    ans %= MOD;
    g << (1ll * ans * inv) % MOD << '\n';
  }
  return 0;
}
