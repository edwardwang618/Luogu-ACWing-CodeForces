#include <iostream>
#include <set>
using namespace std;

int n;
set<int> st;
int res;

int main() {
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    int diff = 1e9;
    auto it1 = st.lower_bound(x);
    if (it1 != st.end()) diff = min(diff, abs(*it1 - x));
    if (it1 != st.begin()) {
      auto it2 = prev(it1);
      diff = min(diff, abs(*it2 - x));
    }
    res += diff == (int)1e9 ? x : diff;
    st.insert(x);
  }

  printf("%d\n", res);
}