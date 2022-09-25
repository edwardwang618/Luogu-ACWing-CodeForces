#include <iostream>
using namespace std;

const int N = 100010;
int n, m;
int h[N], &sz = h[0];

void sift_down(int u) {
  int x = h[u];
  while (u << 1 <= sz) {
    int t = u << 1;
    if (t + 1 <= sz && h[t + 1] < h[t]) t++;
    if (x < h[t]) break;
    h[u] = h[t];
    u = t;
  }
  h[u] = x;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) cin >> h[i];
  sz = n;

  for (int i = n / 2; i; i--) sift_down(i);

  while (m--) {
    cout << h[1] << ' ';
    h[1] = h[sz--];
    sift_down(1);
  }
}