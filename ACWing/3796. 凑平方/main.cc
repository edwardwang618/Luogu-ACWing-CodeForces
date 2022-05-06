#include <iostream>
#include <cmath>
using namespace std;

int n;

int cal(int x) {
  string s = to_string(n), t = to_string(x);
  for (int i = 0, j = 0; i < s.size(); i++) {
    if (s[i] == t[j]) j++;
    if (j == t.size()) return s.size() - t.size();
  }

  return -1;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    int res = -1;
    for (int i = (int) sqrt(n); i >= 1; i--) {
      int x = cal(i * i);
      if (~x) {
        res = x;
        break;
      }
    }
    printf("%d\n", res);
  }
}