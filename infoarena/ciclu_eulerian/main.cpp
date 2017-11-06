#include <bitset>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>
#define MAXN 100010
#define maxb 100000
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
char buf[maxb];
vector<pair<int, int>> G[MAXN];
vector<int> ans;
stack<int> st;
bitset<5 * MAXN> viz;
int n, m, gr[MAXN], x, y, w, urm, nr, poz(maxb), muchie;
int getint() {
  int nr = 0;
  while (buf[poz] < '0' || buf[poz] > '9')
    if (++poz >= maxb) {
      f.read(buf, maxb);
      poz = 0;
    }
  while (buf[poz] >= '0' && buf[poz] <= '9') {
    nr = nr * 10 + buf[poz] - '0';
    if (++poz >= maxb) {
      f.read(buf, maxb);
      poz = 0;
    }
  }
  return nr;
}
int main() {
  n = getint();
  m = getint();
  while (m--) {
    x = getint();
    y = getint();
    G[x].push_back(make_pair(y, m));
    G[y].push_back(make_pair(x, m));
  }
  for (int i = 1; i <= n; ++i) {
    if (G[i].size() % 2) {
      g << -1;
      return 0;
    }
  }
  st.push(1);
  while (st.size()) {
    w = st.top();
    if (!G[w].empty()) {
      urm = G[w][G[w].size() - 1].first;
      muchie = G[w][G[w].size() - 1].second;
      G[w].pop_back();
      if (!viz[muchie]) {
        viz[muchie] = 1;
        st.push(urm);
      }
    } else {
      ans.push_back(w);
      st.pop();
    }
  }
  ans.pop_back();
  for (auto it : ans)
    g << it << ' ';
  return 0;
}
