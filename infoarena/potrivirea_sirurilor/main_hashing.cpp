#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
#define P1 307
#define P2 311
#define MOD1 100007
#define MOD2 100013
#define MAXN 2000005
int v[MAXN], n, m, nr;
char s1[MAXN], s2[MAXN];
int hashA1, hashA2, hash1, hash2, P11, P22;
int int_mod(int a, int b) { return (a % b + b) % b; }
int main() {
  f.getline(s1, MAXN);
  f.getline(s2, MAXN);
  n = strlen(s1);
  m = strlen(s2);
  if (n > m) {
    g << "0\n";
    return 0;
  }
  P11 = P22 = 1;
  for (int i = 0; i < n; i++) {
    hashA1 = (hashA1 * P1 + s1[i]) % MOD1;
    hashA2 = (hashA2 * P2 + s1[i]) % MOD2;
    if (i != 0) {
      P11 = (P11 * P1) % MOD1;
      P22 = (P22 * P2) % MOD2;
    }
  }
  for (int i = 0; i < n; i++) {
    hash1 = (hash1 * P1 + s2[i]) % MOD1;
    hash2 = (hash2 * P2 + s2[i]) % MOD2;
  }
  if (hash1 == hashA1 && hash2 == hashA2) {
    v[0]++;
    nr++;
  }
  for (int i = n; i < m; i++) {
    hash1 =
        ((int_mod(hash1 - (P11 * s2[i - n]), MOD1) * P1) % MOD1 + s2[i]) % MOD1;
    hash2 =
        ((int_mod(hash2 - (P22 * s2[i - n]), MOD2) * P2) % MOD2 + s2[i]) % MOD2;
    if (hash1 == hashA1 && hash2 == hashA2) {
      ++nr;
      v[i - n + 1]++;
    }
  }
  g << nr << '\n';
  nr = 0;
  for (int i = 0; i < m && nr < 1000; i++) {
    if (v[i] == 1) {
      g << i << ' ';
      nr++;
    }
  }
  return 0;
}
