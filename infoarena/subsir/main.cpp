#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("subsir.in");
ofstream g("subsir.out");
char s1[502], s2[502];
int n, m, i, j, a[502][502], d[502][502];
int main() {
  f.getline(s1, 502);
  f.getline(s2, 502);
  n = strlen(s1);
  m = strlen(s2);
  for (i = n; i; i--)
    s1[i] = s1[i - 1];
  for (i = m; i; i--)
    s2[i] = s2[i - 1];
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (s1[i] == s2[j])
        a[i][j] = a[i - 1][j - 1] + 1;
      else
        a[i][j] = max(a[i - 1][j], a[i][j - 1]);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (i == 1 || j == 1)
        d[i][j] = 1;
      else if (s1[i] == s2[j])
        d[i][j] = d[i - 1][j - 1];
      else {
        if (a[i - 1][j] == a[i][j])
          d[i][j] = (d[i - 1][j] + d[i][j]) % 666013;
        if (a[i][j] == a[i][j - 1])
          d[i][j] = (d[i][j - 1] + d[i][j]) % 666013;
        if (a[i][j] == a[i - 1][j - 1])
          d[i][j] = (d[i][j] - d[i - 1][j - 1] + 666013) % 666013;
      }
  g << d[n][m];
  return 0;
}
