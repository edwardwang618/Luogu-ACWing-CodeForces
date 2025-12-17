#include <iostream>
#include <map>
using namespace std;

int n;
map<int, int> mp;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (i > 1) {
      auto it = mp.lower_bound(x);
      if (it != mp.begin()) {
        auto it2 = prev(it);
        if (it == mp.end() || abs(it2->first - x) <= abs(it->first - x))
          it = it2;
      }
      printf("%d %d\n", abs(it->first - x), it->second);
    }
    mp[x] = i;
  }
}