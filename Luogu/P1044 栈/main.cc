#include <iostream>
using namespace std;

const int N = 20;
int n;
int f[N];

int main() {
  scanf("%d", &n);
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < i; j++)
      f[i] += f[j] * f[i - 1 - j];
  
  printf("%d\n", f[n]);
}