#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
#define MOD 666013
ifstream f("hashuri.in");
ofstream g("hashuri.out");
vector<int> H[MOD];
int n, a, b;
int _hashcode(int x) { return x % MOD; }
int _find(int x) {
  int y = _hashcode(x);
  for (auto it : H[y])
    if (it == x)
      return 1;
  return 0;
}
void _insert(int x) {
  int y = _hashcode(x);
  if (_find(x) == 0) {
    H[y].push_back(x);
  }
}
void _delete(int x) {
  int y = _hashcode(x);
  for (int i = 0; i < H[y].size(); i++)
    if (H[y][i] == x) {
      H[y].erase(H[y].begin() + i);
      break;
    }
}
int main() {
  f >> n;
  for (int i = 1; i <= n; i++) {
    f >> a >> b;
    if (a == 1) {
      _insert(b);
    }
    if (a == 2) {
      _delete(b);
    }
    if (a == 3)
      g << _find(b) << '\n';
  }
  return 0;
}
