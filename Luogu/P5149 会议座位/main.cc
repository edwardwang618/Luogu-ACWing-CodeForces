#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], tmp[N];
unordered_map<string, int> mp;

long merge_sort(int l, int r) {
  if (l == r) return 0;
  int mid = l + (r - l >> 1);
  long res = merge_sort(l, mid) + merge_sort(mid + 1, r);
  int i = l, j = mid + 1, idx = l;
  while (i <= mid && j <= r)
    if (a[i] <= a[j]) {
      res += j - mid - 1;
      tmp[idx++] = a[i++];
    } else tmp[idx++] = a[j++];
  while (i <= mid) tmp[idx++] = a[i++], res += r - mid;
  while (j <= r) tmp[idx++] = a[j++];
  for (i = l; i <= r; i++) a[i] = tmp[i];
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    mp[s] = i;
  }

  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    a[i] = mp[s];
  }

  printf("%ld\n", merge_sort(1, n));
}