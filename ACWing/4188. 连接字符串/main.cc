#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n;
char s[N];
int ne[N];

int main() {
  scanf("%d%s", &n, s + 1);
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && s[i] != s[j + 1]) j = ne[j];
    if (s[i] == s[j + 1]) j++;
    ne[i] = j;
  }

  printf("%d\n", n - ne[n]);
}