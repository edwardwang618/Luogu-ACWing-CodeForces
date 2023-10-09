#include <iostream>
#include <climits>
#include <unordered_set>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

int main() {
  scanf("%d%d", &n, &m);
  unordered_set<int> st;
  int res = INT_MAX;
  for (int i = 1, x; i <= n; i++) {
    scanf("%d", &x);
    if (st.count(m - x)) res = min(res, min(x, m - x));
    st.insert(x);
  }
  
  if (res == INT_MAX) puts("No Solution");
  else printf("%d %d\n", res, m - res);
}