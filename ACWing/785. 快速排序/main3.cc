#include <iostream>
using namespace std;

const int N = 100010;
int a[N];

void sift_down(int i, int n) {
  int x = a[i];
  while (i << 1 <= n) {
    int j = i << 1;
    if (j + 1 <= n && a[j + 1] > a[j]) j++;
    if (a[j] > x) a[i] = a[j];
    else break;

    i = j;
  }

  a[i] = x;
}

void heapify(int n) {
  for (int i = n >> 1; i; i--) sift_down(i, n);
}

void heap_sort(int n) {
  heapify(n);
  for (int i = n; i; i--) {
    swap(a[1], a[i]);
    sift_down(1, i - 1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

  heap_sort(n);
  for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}