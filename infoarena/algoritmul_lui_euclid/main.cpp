#include <fstream>
#include <iostream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int x, y, n;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int main() {
  f >> n;
  while (n--) {
    f >> x >> y;
    g << gcd(x, y) << '\n';
  }
  return 0;
}
