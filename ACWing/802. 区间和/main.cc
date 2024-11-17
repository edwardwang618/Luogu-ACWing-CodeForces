#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using PII = pair<int, int>;

const int N = 3e5 + 10;
int n, m;
int a[N], s[N];
vector<int> xs;
vector<PII> adds, qs;
unordered_map<int, int> mp;

int main() {
  scanf("%d%d", &n, &m);
  xs.reserve(n + 2 * m);
  for (int i = 1; i <= n; i++) {
    int x, c;
    scanf("%d%d", &x, &c);
    adds.emplace_back(x, c);
    xs.push_back(x);
  }

  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    qs.emplace_back(l, r);
    xs.push_back(l), xs.push_back(r);
  }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  mp.reserve(xs.size());
  for (int i = 0; i < xs.size(); i++) mp.emplace(xs[i], i + 1);

  for (auto [x, c] : adds) a[mp[x]] += c;
  for (int i = 1; i <= xs.size(); i++) s[i] = s[i - 1] + a[i];

  for (auto [l, r] : qs) printf("%d\n", s[mp[r]] - s[mp[l] - 1]);
}