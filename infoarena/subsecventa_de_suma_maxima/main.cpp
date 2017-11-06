#include <fstream>
#include <iostream>
#define MAXN 6000010
#define INF 1900000000
using namespace std;
ifstream f("ssm.in");
ofstream g("ssm.out");
int v[MAXN], s, n, smax, pi, pf, pic = 1;
int main() {
  f >> n;
  for (int i = 1; i <= n; i++)
    f >> v[i];
  smax = -INF;
  for (int i = 1; i <= n; i++) {
    if (s < 0) {
      s = v[i];
      pic = i;
    } else
      s += v[i];
    if (s > smax) {
      smax = max(smax, s);
      pi = pic;
      pf = i;
    }
  }
  g << smax << ' ' << pi << ' ' << pf;
  return 0;
