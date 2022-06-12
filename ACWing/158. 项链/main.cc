#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e6 + 10;
int n;
char a[N], b[N];

int get_min(char s[]) {
  int i = 0, j = 1, k;
  while (i < n && j < n) {
    for (k = 0; k < n && s[i + k] == s[j + k]; k++);
    if (k == n) break;
    s[i + k] > s[j + k] ? i += k + 1 : j += k + 1;
    if (i == j) j++;
  }

  k = min(i, j);
  s[k + n] = 0;
  return k;
}

int main() {
  scanf("%s%s", a, b);
  n = strlen(a);
  memcpy(a + n, a, n - 1);
  memcpy(b + n, b, n - 1);

  int x = get_min(a), y = get_min(b);
  if (strcmp(a + x, b + y)) puts("No");
  else {
    puts("Yes");
    puts(a + x);
  }
}