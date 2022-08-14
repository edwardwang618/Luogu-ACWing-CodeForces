#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1e4 + 10;
int n, k, a[N], idx;
unordered_set<int> st;

int quick_select(int l, int r) {
  if (l >= r) return a[l];
  int i = l, j = r, piv = a[l + (r - l >> 1)];
  while (i <= j) {
    while (a[i] < piv) i++;
    while (a[j] > piv) j--;
    if (i <= j) {
      swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (k <= j) return quick_select(l, j);
  else if (k >= i) return quick_select(i, r);
  else return a[k];
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    if (!st.count(x)) {
      st.insert(x);
      a[++idx] = x;
    }
  }
  
  if (k < 1 || k > idx) puts("NO RESULT");
  else printf("%d\n", quick_select(1, idx));
}