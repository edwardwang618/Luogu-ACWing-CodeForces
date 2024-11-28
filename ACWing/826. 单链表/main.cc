#include <cstring>
#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], idx;

void init() { head = -1, idx = 0; }

void add_to_head(int x) { e[idx] = x, ne[idx] = head, head = idx++; }

void add(int k, int x) { e[idx] = x, ne[idx] = ne[k], ne[k] = idx++; }

void remove(int k) { ~k ? ne[k] = ne[ne[k]] : head = ne[head]; }

int main() {
  int n;
  scanf("%d", &n);

  init();
  while (n--) {
    char op;
    int k, x;

    cin >> op;
    if (op == 'H') {
      scanf("%d", &x);
      add_to_head(x);
    } else if (op == 'I') {
      scanf("%d%d", &k, &x);
      add(k - 1, x);
    } else if (op == 'D') {
      scanf("%d", &k);
      remove(k - 1);
    }
  }

  while (~head) {
    printf("%d ", e[head]);
    head = ne[head];
  }
}