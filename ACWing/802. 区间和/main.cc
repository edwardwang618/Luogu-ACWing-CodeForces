#include <iostream>
#include <algorithm>
#include <vector>
#define x first
#define y second
using namespace std;
using PII = pair<int, int>;

const int N = 300010;
int n, m;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;

int find(int x) {
  int l = 0, r = alls.size() - 1;
  while (l < r) {
    int m = l + (r - l >> 1);
    if (alls[m] >= x) r = m;
    else l = m + 1;
  }

  return l + 1;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, c;
    cin >> x >> c;
    add.push_back({x, c});
    alls.push_back(x);
  }

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
    alls.push_back(l);
    alls.push_back(r);
  }

  sort(alls.begin(), alls.end());
  alls.erase(unique(alls.begin(), alls.end()), alls.end());

  for (auto item : add) {
    int x = find(item.x);
    a[x] += item.y;
  }

  for (int i = 1; i <= alls.size(); i++) s[i] = s[i - 1] + a[i];

  for (auto item : query) {
    int l = find(item.x), r = find(item.y);
    cout << s[r] - s[l - 1] << endl;
  }
}