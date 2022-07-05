#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
int h[N], sz;

void sift_up(int k) {
  while (k > 1 && h[k] < h[k >> 1]) {
    swap(h[k], h[k >> 1]);
    k >>= 1;
  }
}

void sift_down(int k) {
  while (k * 2 <= sz) {
    int t = k;
    if (h[k * 2] < h[t]) t = k * 2;
    if (k * 2 + 1 <= sz && h[k * 2 + 1] < h[t]) t = k * 2 + 1;
    if (t == k) return;
    swap(h[k], h[t]);
    k = t;
  }
}

void push(int x) {
  h[++sz] = x;
  sift_up(sz);
}

void pop() {
  h[1] = h[sz--];
  sift_down(1);
}

int main() {
  scanf("%d", &n);
  while (n--) {
    int op, x;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d", &x);
      push(x);
    } else if (op == 2) printf("%d\n", h[1]);
    else pop();
  }
}