#include <cstring>
#include <iostream>
using namespace std;

const int N = 100003;
int h[N], e[N], ne[N], idx;

void insert(int x) {
  int k = (x % N + N) % N;
  e[idx] = x, ne[idx] = h[k], h[k] = idx++;
}

bool find(int x) {
  int k = (x % N + N) % N;
  for (int i = h[k]; ~i; i = ne[i])
    if (e[i] == x) return true;

  return false;
}

int main() {
  int n;
  cin >> n;

  memset(h, -1, sizeof h);

  while (n--) {
    char op[2];
    int x;
    cin >> op;
    cin >> x;
    if (op[0] == 'I')
      insert(x);
    else if (op[0] == 'Q')
      find(x) ? puts("Yes") : puts("No");
  }
}