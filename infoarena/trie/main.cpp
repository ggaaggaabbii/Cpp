#include <fstream>
#include <iostream>
#include <string.h>
using namespace std;
ifstream f("trie.in");
ofstream g("trie.out");
struct nod {
  int pr, nrap;
  nod *nextnod[27];
  nod() {
    pr = nrap = 0;
    memset(nextnod, 0, sizeof(nextnod));
  }
} * K;
char s[25];
int op, n;
void adaug() {
  nod *q = K;
  q->pr++;
  for (int i = 0; i < n; i++) {
    if (q->nextnod[s[i]] == 0)
      q->nextnod[s[i]] = new nod;
    q = q->nextnod[s[i]];
    q->pr++;
  }
  q->nrap++;
}
void del() {
  nod *q = K;
  q->pr--;
  for (int i = 0; i < n; i++) {
    q = q->nextnod[s[i]];
    q->pr--;
  }
  q->nrap--;
}
int prefix() {
  nod *q = K;
  for (int i = 0; i < n; i++) {
    if (q->nextnod[s[i]] == 0 || q->nextnod[s[i]]->pr == 0)
      return i;
    q = q->nextnod[s[i]];
  }
  return n;
}
int cuv() {
  nod *q = K;
  for (int i = 0; i < n; i++) {
    if (q->nextnod[s[i]] == 0)
      return 0;
    q = q->nextnod[s[i]];
  }
  return q->nrap;
}
int main() {
  K = new nod;
  while (f >> op) {
    f.get();
    f.getline(s, 20);
    n = strlen(s);
    for (int i = 0; i < n; i++)
      s[i] -= 'a';
    if (op == 0)
      adaug();
    if (op == 1)
      del();
    if (op == 3)
      g << prefix() << '\n';
    if (op == 2)
      g << cuv() << '\n';
  }
  return 0;
}
