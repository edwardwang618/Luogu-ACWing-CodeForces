#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
using ull = unsigned long long;

const int N = 1010, M = N * N, P = 131;
int n, m, a, b, q, Case;
ull ha[N][N], po[M];
char s[N];

ull calc(ull f[], int l, int r) { return f[r] - f[l - 1] * po[r - l + 1]; }

int main() {
  po[0] = 1;
  scanf("%d%d%d%d", &m, &n, &a, &b);
  for (int i = 1; i <= n * m; i++)
    po[i] = po[i - 1] * P;
  for (int i = 1; i <= m; i++) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; j++)
      ha[i][j] = ha[i][j - 1] * P + s[j];
  }
  unordered_set<ull> st;
  vector<ull> qs;
  scanf("%d", &q);
  while (q--) {
    ull h = 0;
    for (int i = 0; i < a; i++) {
      scanf("%s", s);
      for (int j = 0; j < b; j++)
        h = h * P + s[j];
    }
    st.insert(h);
    qs.push_back(h);
  }
  for (int i = b; i <= m; i++) {
    ull h = 0;
    int l = i - b + 1, r = i;
    for (int j = 1; j <= n; j++) {
      h = h * po[b] + calc(ha[j], l, r);
      if (j > a)
        h -= calc(ha[j - a], l, r) * po[a * b];
      if (j >= a)
        st.erase(h);
    }
  }
  for (int q : qs)
    printf("%d\n", st.count(q) ? 0 : 1);
}
