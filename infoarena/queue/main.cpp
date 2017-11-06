#include <fstream>
#include <iostream>
#include <stack>
using namespace std;
ifstream f("queue.in");
ofstream g("queue.out");
stack<int> S1, S2;
char x;
int op, n, nr, k, nr1;
int main() {
  f >> n;
  for (int i = 1; i <= n; i++) {
    f >> x >> x;
    if (x == 'u') {
      for (int j = 1; j <= 8; j++)
        f >> x;
      f >> nr;
      f >> x;
      op = 1;
    } else {
      for (int j = 1; j <= 9; j++)
        f >> x;
      op = 2;
    }
    if (op == 1) {
      S1.push(nr);
      g << ++k << ": "
        << "read(" << nr << ") "
        << "push(1," << nr << ")\n";
    } else {
      if (!S2.empty()) {
        nr1 = S2.top();
        S2.pop();
        g << ++k << ": pop(2) write(" << nr1 << ")\n";
      } else {
        g << ++k << ": ";
        while (!S1.empty()) {
          nr1 = S1.top();
          S1.pop();
          if (S1.empty()) {
            g << "pop(1) write(" << nr1 << ") ";
          } else {
            S2.push(nr1);
            g << "pop(1) push(2," << nr1 << ") ";
          }
        }
        g << '\n';
      }
    }
  }
  return 0;
}
