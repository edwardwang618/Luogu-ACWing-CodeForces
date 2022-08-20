#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
long a[N];
long h[N];
int sz;

void sift_up(int k) {
  while (k > 1 && h[k] > h[k >> 1]) {
    swap(h[k], h[k >> 1]);
    k >>= 1;
  }
}

void sift_down(int k) {
  while (k * 2 <= sz) {
    int t = k;
    if (h[k * 2] > h[t]) t = k * 2;
    if (k * 2 + 1 <= sz && h[k * 2 + 1] > h[t]) t = k * 2 + 1;
    if (t == k) return;
    swap(h[k], h[t]);
    k = t;
  }
}

void push(long x) {
  h[++sz] = x;
  sift_up(sz);
}

void pop() {
  h[1] = h[sz--];
  sift_down(1);
}

#define top() h[1]

int main() {
  scanf("%d", &n);
  long res = 0;
  for (int i = 1; i <= n; i++) {
    long x;
    scanf("%ld", &x);
    x -= i;
    push(x);
    if (top() > x) {
      res += top() - x;
      pop();
      push(x);
    }
    a[i] = top();
  }

  printf("%ld\n", res);
  for (int i = n - 1; i; i--) a[i] = min(a[i], a[i + 1]);
  for (int i = 1; i <= n; i++) printf("%ld ", a[i] + i);
}