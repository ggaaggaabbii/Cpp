#include <fstream>
#include <iostream>
using namespace std;
ifstream f("2sah.in");
ofstream g("2sah.out");
long long nr, p1, p2, k, t, n, a[5][5], aux[5][5], mat[5][5], i, j, l, p;
void inmultire() {
  for (i = 1; i <= 3; i++)
    for (l = 1; l <= 3; l++)
      aux[i][l] = mat[i][l];
  for (i = 1; i <= 3; i++)
    for (l = 1; l <= 3; l++) {
      mat[i][l] = 0;
      for (p = 1; p <= 3; p++)
        mat[i][l] += ((a[i][p] * aux[p][l])) % 100003;
    }
}
void patrat() {
  for (i = 1; i <= 3; i++)
    for (l = 1; l <= 3; l++)
      aux[i][l] = a[i][l];
  for (i = 1; i <= 3; i++)
    for (l = 1; l <= 3; l++) {
      a[i][l] = 0;
      for (p = 1; p <= 3; p++)
        a[i][l] += ((aux[i][p] * aux[p][l])) % 100003;
    }
}
int main() {
  f >> t >> n >> k;
  if (t == 1) {
    nr = 1;
    p1 = 3;
    p2 = k - 1;
    while (p2) {
      if (p2 % 2 == 1)
        nr *= p1;
      nr = nr % 100003;
      p1 = ((p1 % 100003) * (p1 % 100003)) % 100003;
      p2 /= 2;
    }
    g << nr;
  } else {
    a[1][2] = 1;
    a[2][3] = 1;
    for (i = 1; i <= 3; i++)
      a[3][i] = 1;
    for (i = 1; i <= 3; i++)
      mat[i][i] = 1;
    j = n - k + 1;
    while (j) {
      if (j % 2 == 1)
        inmultire();
      patrat();
      j /= 2;
    }
    g << (mat[1][1] + mat[1][2] + 2 * mat[1][3]) % 100003;
  }
  return 0;
}
