#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int N = 1010;
pair<int, int> p[N];
int n;

vector<int> mul(vector<int> a, int b) {
  vector<int> c;
  for (int i = 0, t = 0; i < a.size() || t; i++) {
    if (i < a.size())
      t += a[i] * b;
    c.push_back(t % 10);
    t /= 10;
  }

  return c;
}

vector<int> div(vector<int> a, int b) {
  vector<int> c;
  for (int i = a.size() - 1, t = 0; i >= 0; i--) {
    t = t * 10 + a[i];
    int d = t / b;
    if (d || !c.empty())
      c.push_back(d);
    t %= b;
  }

  reverse(c.begin(), c.end());
  if (c.empty())
    c.push_back(0);
  return c;
}

vector<int> maxv(vector<int> a, vector<int> b) {
  if (a.size() != b.size())
    return a.size() > b.size() ? a : b;
  for (int i = a.size() - 1; i >= 0; i--)
    if (a[i] != b[i])
      return a[i] > b[i] ? a : b;

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> p[0].first >> p[0].second;

  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    p[i] = {x * y, y};
  }

  sort(p + 1, p + n + 1);

  vector<int> res{0};
  vector<int> prod{1};
  prod = mul(prod, p[0].first);

  for (int i = 1; i <= n; i++) {
    res = maxv(res, div(prod, p[i].second));
    prod = mul(prod, p[i].first / p[i].second);
  }

  for (int i = res.size() - 1; i >= 0; i--)
    cout << res[i];
  cout << '\n';
}
