#include <iostream>
#include <vector>
using namespace std;

const int N = 6e4 + 10;
int n;
int ps[N], cnt;
bool st[N];
int sum[N];

void get_primes(int n) {
  for (int i = 2; i <= n; i++) {
    if (!st[i]) ps[cnt++] = i;
    for (int j = 0; ps[j] <= n / i; j++) {
      st[ps[j] * i] = true;
      if (i % ps[j] == 0) break;
    }
  }
}

int get(int n, int p) {
  int res = 0;
  while (n) {
    res += n / p;
    n /= p;
  }
  return res;
}

void mul(vector<int> &a, int b) {
  int t = 0;
  for (int i = 0; i < a.size(); i++) {
    t += a[i] * b;
    a[i] = t % 10000;
    t /= 10000;
  }

  while (t) {
    a.push_back(t % 10000);
    t /= 10000;
  }
}

int main() {
  scanf("%d", &n);
  int a = 2 * n, b = n;

  get_primes(a);

  for (int i = 0; i < cnt; i++) {
    int p = ps[i];
    sum[i] = get(a, p) - get(b, p) - get(b + 1, p);
  }

  vector<int> res{1};

  for (int i = 0; i < cnt; i++)
    for (int j = 0; j < sum[i]; j++) mul(res, ps[i]);

  printf("%d", res.back());
  for (int i = res.size() - 2; i >= 0; i--) printf("%04d", res[i]);
}
