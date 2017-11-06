#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid3.in");
ofstream g("euclid3.out");
int n, a, b, c, d, x, y;
int gcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d, x0, y0;
  d = gcd(b, a % b, x0, y0);
  x = y0;
  y = x0 - y0 * (a / b);
  return d;
}
int main() {
  f >> n;
  while (n--) {
    f >> a >> b >> c;
    d = gcd(a, b, x, y);
    if (c % d == 0)
      g << c / d * x << ' ' << c / d * y << '\n';
    else
      g << "0 0\n";
  }
  return 0;
}
