#include <deque>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("carti3.in");
ofstream g("carti3.out");
deque<int> D;
int n, x, c, ok = 1;
int main() {
  f >> n >> c;
  for (int i = 1; i <= c; i++) {
    f >> x;
    D.push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    f >> x;
    if (x == -1) {
      ok *= x;
    } else if (ok == 1) {
      D.push_front(x);
    } else
      D.push_back(x);
  }
  if (ok == 1)
    while (D.size()) {
      g << D.front() << '\n';
      D.pop_front();
    }
  else
    while (D.size()) {
      g << D.back() << '\n';
      D.pop_back();
    }
  return 0;
}
