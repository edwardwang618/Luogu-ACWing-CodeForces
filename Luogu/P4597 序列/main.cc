#include <iostream>
#include <queue>
using namespace std;

const int N = 5e5 + 10;
int n;
priority_queue<long> heap;

int main() {
  scanf("%d", &n);
  long res = 0;
  for (int i = 1; i <= n; i++) {
    long x;
    scanf("%ld", &x);
    heap.push(x);
    if (heap.top() > x) {
      res += heap.top() - x;
      heap.pop();
      heap.push(x);
    }
  }

  printf("%ld\n", res);
}