#include <fstream>
#include <iostream>
using namespace std;
long long a, b, c, d, e, f, minim, s;
ifstream fin("minarea.in");
ofstream g("minarea.out");
int main() {
  fin >> a >> b >> c >> d >> e >> f;
  if (c < f) {
    swap(a, d);
    swap(b, e);
    swap(c, f);
  }
  // cuplare 3 cu 3
  s += 9 * f;
  c -= f;
  f = 0;
  // cuplare 3 cu 2 - 1
  minim = min(c, min(e, d));
  s += 9 * minim;
  c -= minim;
  e -= minim;
  d -= minim;
  // cuplare 3 cu 1 - 1 - 1
  minim = min(c, d / 3);
  s += 9 * minim;
  c -= minim;
  d -= 3 * minim;
  // cuplare 3 - 1 cu 2 - 2
  minim = min(c, min(a, e / 2));
  s += 12 * minim;
  c -= minim;
  a -= minim;
  e -= 2 * minim;
  // cuplare 3 - 3 cu 2 - 2 - 2
  minim = min(c / 2, e / 3);
  s += 24 * minim;
  c -= 2 * minim;
  e -= 3 * minim;
  // cuplare 2 cu 2
  minim = min(b, e);
  s += 4 * minim;
  b -= minim;
  e -= minim;
  if (b < e) {
    swap(b, e);
    swap(a, d);
    swap(c, f);
  }
  // cuplare 2 cu 1 - 1
  minim = min(b, d / 2);
  s += 4 * minim;
  d -= 2 * minim;
  b -= minim;
  // cuplare 1 cu 1
  s += min(a, d);
  g << s;
  fin.close();
  g.close();
  return 0;
}
