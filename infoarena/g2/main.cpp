#include <fstream>
#include <iostream>
using namespace std;
ifstream f("g2.in");
ofstream g("g2.out");
long long n, r, p = 1, i = 9;
int main() {
  f >> n;
  while (i > 1) {
    while (!(n % i)) {
      r = p * i + r;
      p *= 10;
      n /= i;
    }
    i--;
  }
  g << r;
}
