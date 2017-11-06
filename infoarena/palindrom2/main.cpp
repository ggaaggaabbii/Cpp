#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
#define MAXN 2010
ifstream f("palindrom2.in");
ofstream g("palindrom2.out");
char a[MAXN], b[MAXN];
int n, k, dp[2 * MAXN];
void palindrom() {
  dp[0] = 0;
  dp[1] = 0;
  for (int i = 2; i <= 2 * n - 1; i++) {
    while (k > 0 && b[i] != b[k + 1])
      k = dp[k];
    if (b[i] == b[k + 1])
      k++;
    dp[i] = k;
  }
}
int main() {
  a[0] = 'a';
  f.getline(a + 1, MAXN);
  n = strlen(a);
  b[0] = 'a';
  for (int i = n - 1; i > 0; i--)
    b[n - i] = a[i];
  strcat(b + n, a);
  palindrom();
  g << a + 1;
  for (int i = 1 + dp[2 * n - 1]; i < n; i++)
    g << b[i];
  return 0;
}
