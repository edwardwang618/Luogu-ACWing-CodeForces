#include <iostream>
using namespace std;

const int N = 100010;
int e[N], l[N], r[N], idx;

void init() {
  r[0] = 1, l[1] = 0;
  idx = 2;
}

// 在下标是k的边的右边插入x
void add(int k, int x) {
  e[idx] = x;
  l[idx] = k;
  r[idx] = r[k];
  l[r[k]] = idx;
  r[k] = idx;
  idx++;
}

void remove(int k) {
  r[l[k]] = r[k];
  l[r[k]] = l[k];
}

int main() {
  int n;
  cin >> n;

  init();
  while (n--) {
    string op;
    cin >> op;
    int k, x;
    if (op == "L") {
      cin >> x;
      add(0, x);
    } else if (op == "R") {
      cin >> x;
      add(l[1], x);
    } else if (op == "D") {
      cin >> k;
      remove(k + 1);
    } else if (op == "IL") {
      cin >> k >> x;
      add(l[k + 1], x);
    } else if (op == "IR") {
      cin >> k >> x;
      add(k + 1, x);
    }
  }

  int head = r[0];
  while (head != 1) {
    cout << e[head] << " ";
    head = r[head];
  }
}