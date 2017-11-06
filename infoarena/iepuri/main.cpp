#include <fstream>
#include <iostream>
#define MOD 666013
using namespace std;
ifstream f("iepuri.in");
ofstream g("iepuri.out");
long a[5][5], b[5][5], c[5][5], v[5], rez, t, n;
void inm() {
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= 3; k++) {
        c[i][j] += (1ll * b[i][k] * a[k][j]) % MOD;
        c[i][j] %= MOD;
      }
    }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      b[i][j] = c[i][j];
}
void patrat() {
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= 3; k++) {
        c[i][j] += (1ll * a[i][k] * a[k][j]) % MOD;
        c[i][j] %= MOD;
      }
    }
  for (int i = 1; i <= 3; i++)
    for (int j = 1; j <= 3; j++)
      a[i][j] = c[i][j];
}
int main() {
  f >> t;
  while (t--) {
    f >> v[1] >> v[2] >> v[3] >> a[3][3] >> a[2][3] >> a[1][3] >> n;
    for (int i = 1; i <= 3; i++)
      b[i][i] = 1;
    a[2][1] = 1;
    a[3][2] = 1;
    n -= 2;
    while (n) {
      if (n % 2 == 1)
        inm();
      patrat();
      n /= 2;
    }
    rez = 0;
    for (int i = 1; i <= 3; i++) {
      rez += (1ll * v[i] * b[i][3]) % MOD;
      rez %= MOD;
    }
    for (int i = 1; i <= 3; i++)
      for (int j = 1; j <= 3; j++)
        a[i][j] = b[i][j] = c[i][j] = 0;
    g << rez << '\n';
  }
  return 0;
}
