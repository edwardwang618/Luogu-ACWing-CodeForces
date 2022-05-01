#include <iostream>
#include <map>
using namespace std;

const int N = 2e5 + 10;
int n;
long cnt[N];
map<long, int> b;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    long l, r;
    scanf("%ld%ld", &l, &r);
    b[l]++, b[r + 1]--;
  }

  long sum = 0, last = -1;
  for (auto& [k, v] : b) {
    if (~last) cnt[sum] += k - last;
    sum += v;
    last = k;
  }

  for (int i = 1; i <= n; i++) printf("%ld ", cnt[i]);
}