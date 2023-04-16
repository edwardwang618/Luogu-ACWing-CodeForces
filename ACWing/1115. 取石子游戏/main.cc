#include <iostream>
using namespace std;

bool dfs(int a, int b) {
  if (a / b >= 2 || a == b) return true;
  return !dfs(b, a - b);
}

int main() {
  int a, b;
  while (cin >> a >> b, a | b) {
    if (a < b) swap(a, b);
    dfs(a, b) ? puts("win") : puts("lose");
  }
}