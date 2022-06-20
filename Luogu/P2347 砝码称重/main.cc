#include <iostream>
using namespace std;

const int N = 1010;
int a[10], w[] = {1, 2, 3, 5, 10, 20};
bool f[N];

int main() {
  for (int i = 0; i < 6; i++)
    scanf("%d", &a[i]);

  f[0] = true;
  for (int i = 0; i < 6; i++)
    for (int j = 1; j <= a[i]; j++)
      for (int k = 1000; k >= 0; k--)
        if (k + w[i] <= 1000)
          f[k + w[i]] |= f[k];

  int res = 0;
  for (int i = 1; i <= 1000; i++) if (f[i]) res++;
  printf("Total=%d\n", res);
}