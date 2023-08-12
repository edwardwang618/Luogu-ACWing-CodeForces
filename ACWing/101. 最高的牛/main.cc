#include <iostream>
#include <unordered_set>
using namespace std;
using PII = pair<int, int>;

const int N = 10010;
int h[N];
auto cmp = [](const PII& p) {
  return hash<int>()(p.first) ^ hash<int>()(p.second);
};
unordered_set<PII, decltype(cmp)> st(0, cmp);

int main() {
  int n, p, H, m;
  scanf("%d%d%d%d", &n, &p, &H, &m);
  h[1] = H;
  for (int i = 0, a, b; i < m; i++) {
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    if (a + 1 == b) continue;
    if (!st.count({a, b})) {
      st.insert({a, b});
      h[a + 1]--, h[b]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    h[i] += h[i - 1];
    printf("%d\n", h[i]);
  }
}