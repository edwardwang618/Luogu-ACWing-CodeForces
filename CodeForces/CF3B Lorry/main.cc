#include <iostream>
#include <algorithm>
using namespace std;
using PII = pair<int, int>;

const int N = 1e5 + 10;
int n, v;
PII v1[N], v2[N];
int cnt1, cnt2;
int pre[N];
int res, max1, max2;

int main() {
  scanf("%d%d", &n, &v);
  for (int i = 1; i <= n; i++) {
    int t, p;
    scanf("%d%d", &t, &p);
    if (t == 1) v1[++cnt1] = {p, i};
    else v2[++cnt2] = {p, i};
  }

  sort(v1 + 1, v1 + 1 + cnt1, greater<>());
  sort(v2 + 1, v2 + 1 + cnt2, greater<>());

  for (int i = 1; i <= cnt2; i++)
    pre[i] = v2[i].first + pre[i - 1];

  for (int i = 0, sum = 0; i <= min(cnt1, v); i++) {
    sum += v1[i].first;
    int j = min(v - i >> 1, cnt2);
    if (sum + pre[j] > res) {
      res = sum + pre[j];
      max1 = i;
      max2 = j;
    }
  }

  printf("%d\n", res);
  for (int i = 1; i <= max1; i++) printf("%d ", v1[i].second);
  for (int i = 1; i <= max2; i++) printf("%d ", v2[i].second);
}