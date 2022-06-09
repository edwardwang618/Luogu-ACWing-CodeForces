#include <iostream>
#include <cstring>
using namespace std;

const int N = 5e5 + 10;
char s[N];
int n, m;
int sa[N], rk[N], y[N], c[N], he[N];
int stk[N], top;

void get_sa() {
  for (int i = 1; i <= n; i++) c[rk[i] = s[i]]++;
  for (int i = 2; i <= m; i++) c[i] += c[i - 1];
  for (int i = n; i; i--) sa[c[rk[i]]--] = i;

  for (int k = 1;; k <= 1) {
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
    if (m == num) break;
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

long get_sum() {
  long res = 0;
  for (int i = 2; i <= n; i++) {
    while (top && he[stk[top - 1]] > he[i]) {
      int idx = stk[--top];
      int l = idx - (top ? stk[top - 1] : 1), r = i - idx;
      res += (long) he[idx] * l * r;
    }
    stk[top++] = i;
  }
  while (top) {
    int idx = stk[--top];
    int l = idx - (top ? stk[top - 1] : 1), r = n + 1 - idx;
    res += (long) he[idx] * l * r;
  }
  return res;
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1), m = 'z';

  get_sa();
  get_height();

  printf("%ld\n", (long) n * (n + 1) / 2 * (n - 1) - 2 * get_sum());
}