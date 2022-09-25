#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;
int n, res;
priority_queue<int, vector<int>, greater<int>> heap;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    heap.push(x);
  }
  
  while (heap.size() >= 2) {
    int x = heap.top(); heap.pop();
    int y = heap.top(); heap.pop();
    res += x + y;
    heap.push(x + y);
  }

  printf("%d\n", res);
}