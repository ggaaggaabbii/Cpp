#include <cmath>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("antobroasca.in");
ofstream g("antobroasca.out");
int gcd(int a, int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
int t, x, y, z, A, B;
int main() {
  f >> t;
  while (t--) {
    f >> x >> y >> z >> A >> B;
    if ((int)abs(A) % gcd(x, z) == 0 && (int)abs(B) % gcd(y, z) == 0 &&
        (int)abs(A - B) % gcd(x, y) == 0)
      g << "DA\n";
    else
      g << "NU\n";
  }
  return 0;
}
