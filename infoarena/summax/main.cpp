#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MAXN 2010
vector<int> A[MAXN];
vector<char> B[MAXN];
ifstream f("summax.in");
ofstream g("summax.out");
int p, n, st, dr, x, stiva[MAXN], nr;
void drum(int poz1, int poz2) {
  stiva[poz1] = poz2;
  if (poz1 == n)
    return;
  if (B[poz1][poz2] == '1') {
    drum(poz1 + 1, poz2);
  }
  if (B[poz1][poz2] == '2')
    drum(poz1 + 1, poz2 + 1);
  if (B[poz1][poz2] == '3') {
    if (A[poz1 + 1][poz2] >= x)
      drum(poz1 + 1, poz2);
    else {
      x -= A[poz1 + 1][poz2];
      drum(poz1 + 1, poz2 + 1);
    }
  }
}
void afis() {
  for (int i = 1; i <= n; i++)
    g << stiva[i] + 1 << ' ';
}
int main() {
  f >> p >> n >> st >> dr;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      f >> x;
      A[i].push_back(x);
      B[i].push_back('0');
    }
  }

  for (int i = n - 1; i >= 1; i--)
    for (int j = 0; j < i; j++)
      A[i][j] += max(A[i + 1][j], A[i + 1][j + 1]);
  for (int i = 1; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (A[i + 1][j] == A[i + 1][j + 1])
        B[i][j] = '3';
      else if (A[i + 1][j] > A[i + 1][j + 1])
        B[i][j] = '1';
      else
        B[i][j] = '2';
    }
  for (int i = 0; i < n; i++) {
    A[n][i] = 1;
  }
  for (int i = n - 1; i >= 1; i--)
    for (int j = 0; j < i; j++) {
      if (B[i][j] == '3') {
        if ((long long)A[i + 1][j] + A[i + 1][j + 1] > 2000000000)
          A[i][j] = 2000000001;
        else
          A[i][j] = A[i + 1][j] + A[i + 1][j + 1];
      } else if (B[i][j] == '1')
        A[i][j] = A[i + 1][j];
      else
        A[i][j] = A[i + 1][j + 1];
    }
  if (p == 1) {
    g << A[1][0];
    return 0;
  }
  for (int i = st; i <= dr; i++) {
    x = i;
    nr = 0;
    drum(1, 0);
    afis();
    g << '\n';
  }
  return 0;
}
