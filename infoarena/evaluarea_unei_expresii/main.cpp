#include <fstream>
#include <iostream>
#include <string.h>
#define MAXN 100010
using namespace std;
ifstream f("evaluare.in");
ofstream g("evaluare.out");
int sum_dif();
int mul_div();
int build_nr();
char a[MAXN], *p;
int main() {
  f.getline(a, MAXN);
  p = a;
  g << sum_dif();
  return 0;
}
int sum_dif() {
  int r = mul_div();
  while (*p == '+' || *p == '-') {
    if (*p == '+') {
      ++p;
      r += mul_div();
    } else {
      ++p;
      r -= mul_div();
    }
  }
  return r;
}
int mul_div() {
  int r = build_nr();
  while (*p == '*' || *p == '/') {
    if (*p == '*') {
      ++p;
      r *= build_nr();
    } else {
      ++p;
      r /= build_nr();
    }
  }
  return r;
}
int build_nr() {
  int r = 0;
  if (*p == '(') {
    ++p;
    r = sum_dif();
    ++p;
    return r;
  }
  while (*p >= '0' && *p <= '9') {
    r = r * 10 + *p - '0';
    ++p;
  }
  return r;
}
