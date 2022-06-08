#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
int n, m;
int s[N];
int sa[N], rk[N], y[N], c[N], he[N];
int u[N], d[N];
long res[N];

int get(int x) {
  static unordered_map<int, int> mp;
  if (!mp.count(x)) mp[x] = ++m;
  return mp[x];
}

void get_sa() {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  for (int k = 1;; k <<= 1) {
    int num = 0;
    for (int i = n - k + 1; i <= n; i++) y[++num] = i;
    for (int i = 1; i <= n; i++) if (sa[i] > k) y[++num] = sa[i] - k;
    for (int i = 1; i <= m; i++) c[i] = 0;
    for (int i = 1; i <= n; i++) c[rk[i]]++;
    for (int i = 2; i <= m; i++) c[i] += c[i - 1];
    for (int i = n; i; i--) sa[c[rk[y[i]]]--] = y[i];
    swap(rk, y);
    rk[sa[1]] = num = 1;
    for (int i = 2; i <= n; i++)
      rk[sa[i]] = y[sa[i]] == y[sa[i - 1]] && y[sa[i] + k] == y[sa[i - 1] + k] ? num : ++num;
    if (num == n) break;
    m = num;
  }
}

void get_height() {
  for (int i = 1, k = 0; i <= n; i++) {
    if (rk[i] == 1) continue;
    if (k) k--;
    int j = sa[rk[i] - 1];
    while (i + k <= n && j + k <= n && s[i + k] == s[j + k]) k++;
    he[rk[i]] = k;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = n; i; i--) scanf("%d", &s[i]), s[i] = get(s[i]);

  get_sa();
  get_height();
  
  long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += n - sa[i] + 1 - he[i];
    u[i] = i - 1, d[i] = i + 1;
  }
  d[0] = 1, u[n + 1] = n;

  for (int i = 1; i <= n; i++) {
    res[i] = ans;
    int k = rk[i], j = d[k];
    ans -= n - sa[k] + 1 - he[k];
    ans -= n - sa[j] + 1 - he[j];
    he[j] = min(he[j], he[k]);
    ans += n - sa[j] + 1 - he[j];
    d[u[k]] = d[k], u[d[k]] = u[k];
  }

  for (int i = n; i; i--) printf("%ld\n", res[i]);
}