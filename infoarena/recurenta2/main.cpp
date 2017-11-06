#include <fstream>
#include <iostream>
#define MOD 666013
using namespace std;
ifstream f("recurenta2.in");
ofstream g("recurenta2.out");
int a[9][9], b[9][9], c[9][9], v[9], rez, t, n, A, B, C, x1, x2;
void inm() {
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 7; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= 7; k++) {
        c[i][j] += (1ll * b[i][k] * a[k][j]) % MOD;
        c[i][j] %= MOD;
      }
    }
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 7; j++)
      b[i][j] = c[i][j];
}
void patrat() {
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 7; j++) {
      c[i][j] = 0;
      for (int k = 1; k <= 7; k++) {
        c[i][j] += (1ll * a[i][k] * a[k][j]) % MOD;
        c[i][j] %= MOD;
      }
    }
  for (int i = 1; i <= 7; i++)
    for (int j = 1; j <= 7; j++)
      a[i][j] = c[i][j];
}
int main() {
  f >> A >> B >> C >> x1 >> x2 >> n;
  v[1] = x1;
  v[2] = x2;
  v[3] = 1;
  v[4] = 2;
  v[5] = x1;
  v[6] = 2 * x2;
  v[7] = 2 * x1;
  for (int i = 1; i <= 7; i++)
    b[i][i] = 1;
  if (n == 2) {
    g << v[5];
    return 0;
  }
  n--;
  a[2][1] = 1;
  a[1][2] = B;
  a[2][2] = A;
  a[3][2] = C;
  a[3][3] = 1;
  a[3][4] = 1;
  a[4][4] = 1;
  a[5][5] = 1;
  a[6][5] = 1;
  a[1][6] = B;
  a[2][6] = A;
  a[3][6] = C;
  a[4][6] = C;
  a[6][6] = A;
  a[7][6] = B;
  a[2][7] = 1;
  a[6][7] = 1;
  while (n) {
    if (n % 2 == 1)
      inm();
    patrat();
    n /= 2;
  }
  for (int i = 1; i <= 7; i++) {
    rez += (1ll * v[i] * b[i][5]) % MOD;
    rez %= MOD;
  }
  g << rez;
  return 0;
}
