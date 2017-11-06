#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define MAXN 21
#define MAXM 60
#define INF 1000000000
ifstream f("boom.in");
ofstream g("boom.out");
priority_queue<pair<int, int>> PQ;
pair<int, int> aux;
int viz[(1 << (MAXN - 1)) + 10], dp[(1 << (MAXN - 1)) + 10],
    tata[(1 << (MAXN - 1)) + 10], pas[(1 << (MAXN - 1)) + 10], cost[MAXM], n, m,
    k, v[MAXM], conf, newconf, x, maxnr, pasi;
int get_newconf(int a, int b) {
  int curent = (a & b);
  int l = (curent << 1);
  int r = (curent >> 1);
  curent = (l | r);
  curent &= ((1 << n) - 1);
  return curent;
}
void drum(int nod) {
  if (nod == ((1 << n) - 1)) {
    g << pasi << '\n';
    return;
  }
  pasi++;
  drum(tata[nod]);
  g << pas[nod] << '\n';
}
int main() {
  f >> n >> m;
  for (int i = 0; i <= ((1 << n) - 1); i++)
    dp[i] = INF;
  dp[((1 << n) - 1)] = 0;
  for (int i = 1; i <= m; i++) {
    f >> cost[i];
    f >> k;
    v[i] = (1 << n) - 1;
    for (int j = 1; j <= k; j++) {
      f >> x;
      v[i] -= (1 << (n - x));
    }
  }
  PQ.push(make_pair(0, ((1 << n) - 1)));
  while (PQ.size()) {
    aux = PQ.top();
    PQ.pop();
    conf = aux.second;
    if (conf == 0) {
      g << -aux.first << '\n';
      break;
    }
    if (!viz[conf]) {
      viz[conf] = 1;
      for (int i = 1; i <= m; i++) {
        newconf = get_newconf(conf, v[i]);
        if (!viz[newconf] && dp[conf] + cost[i] < dp[newconf]) {
          dp[newconf] = dp[conf] + cost[i];
          tata[newconf] = conf;
          pas[newconf] = i;
          PQ.push(make_pair(aux.first - cost[i], newconf));
        }
      }
    }
  }
  /*for(int i=0;i<=(1<<n);i++)
      cout<<dp[i]<<' ';*/
  drum(0);
  return 0;
}
