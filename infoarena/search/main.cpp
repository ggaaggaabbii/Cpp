#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
#define MAXN 110
#define INF 6000
#define MAXLEN 5010
ifstream f("search.in");
ofstream g("search.out");
int a[MAXN][MAXLEN][26], n, m, poz, stiva[MAXN][MAXLEN], rez;
char cuvant[MAXN][MAXLEN], x;
void build() {
  int len;
  for (int i = 1; i <= n; i++) {
    len = strlen(cuvant[i]) - 1;
    for (int j = 0; j <= len; j++)
      for (int k = 0; k < 26; k++)
        a[i][j][k] = INF;
  }
  for (int i = 1; i <= n; i++) {
    len = strlen(cuvant[i]) - 1;
    for (int j = len - 1; j >= 0; j--)
      for (int k = 0; k < 26; k++) {
        a[i][j][k] = a[i][j + 1][k];
        if (cuvant[i][j + 1] == 'a' + k)
          a[i][j][k] = j + 1;
      }
  }
}
int main() {
  int len;
  f >> n >> m;
  f.get();
  for (int i = 1; i <= n; i++) {
    cuvant[i][0] = ' ';
    f.getline(cuvant[i] + 1, MAXLEN);
  }
  build();
  while (m--) {
    f >> x;
    if (x == '-')
      poz--;
    else {
      poz++;
      for (int i = 1; i <= n; i++) {
        if (stiva[i][poz - 1] == INF)
          stiva[i][poz] = INF;
        else
          stiva[i][poz] = a[i][stiva[i][poz - 1]][x - 'a'];
      }
    }
    rez = 0;
    for (int i = 1; i <= n; i++)
      if (stiva[i][poz] != INF)
        rez++;
    g << rez << '\n';
  }
  return 0;
}
