#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

const int N = 2e4 + 10;
int n, m, nn;
char s[N];
int sa[N], rk[N], y[N], c[N], he[N];
int l[10], r[10], bel[N], vis[N], cnt;
deque<int> dq;

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
    for (int i = 1; i <= m; i++) c[i] += c[i - 1];
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

void add(int k) {
  if (!bel[k]) return;
  vis[bel[k]]++;
  if (vis[bel[k]] == 1) cnt++;
}

void del(int k) {
  if (!bel[k]) return;
  vis[bel[k]]--;
  if (!vis[bel[k]]) cnt--;
}

int main() {
  scanf("%d", &nn);
  for (int i = 1; i <= nn; i++) {
    l[i] = n + 1;
    scanf("%s", s + n + 1);
    n += strlen(s + n + 1);
    r[i] = n;
    s[++n] = i;
  }

  m = 'z';
  get_sa();
  get_height();
  for (int i = 1; i <= nn; i++)
    for (int j = l[i]; j <= r[i]; j++)
      bel[rk[j]] = i;

  int res = 0;
  for (int i = 1 + nn, j = 1 + nn; i <= n; i++) {
    add(i);
    while (dq.size() && he[dq.back()] >= he[i]) dq.pop_back();
    dq.push_back(i);

    if (cnt == nn) {
      while (cnt == nn && j < i) del(j++);
      add(--j);
    }

    while (dq.size() && dq.front() <= j) dq.pop_front();
    if (cnt == nn) res = max(res, he[dq.front()]);
  }

  printf("%d\n", res);
}