#include <algorithm>
#include <fstream>
#include <iostream>
#include <string.h>
#define MAXN 25010
#define MAXL 110
using namespace std;
ifstream f("dictree.in");
ofstream g("dictree.out");
string s[MAXN];
int n, N, nr, ok;
int main() {
  f >> n;
  f.get();
  for (int i = 1; i <= n; i++)
    getline(f, s[i]);
  sort(s + 1, s + n + 1);
  for (int i = 1; i <= n; i++) {
    ok = 0;
    for (int j = 0; j < s[i].size(); j++)
      if (s[i - 1][j] != s[i][j] || ok == 1) {
        ok = 1;
        nr++;
      }
  }
  g << nr + 1;
  return 0;
}
