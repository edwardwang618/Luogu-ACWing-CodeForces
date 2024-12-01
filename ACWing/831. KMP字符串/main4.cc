#include <iostream>
using namespace std;
using ll = long long;

const int N = 1e6 + 10;
const ll P = 131;
int n, m;
char s[N], p[N];
ll hashP, hashS, po = 1;

int main() {
  scanf("%d", &m);
  scanf("%s", p + 1);
  scanf("%d", &n);
  scanf("%s", s + 1);

  for (int i = 1; i <= m; i++) {
    hashP = hashP * P + p[i];
    po = po * P;
  }

  for (int i = 1; i <= n; i++) {
    hashS = hashS * P + s[i];
    if (i >= m) {
      hashS -= s[i - m] * po;
      if (hashS == hashP) printf("%d ", i - m);
    }
  }
}