#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int ne[N];
int n;
char s[N];
int cs;

int main() {
  static auto build_ne = [&]() {
    for (int i = 2, j = 0; i <= n; i++) {
      while (j && s[i] != s[j + 1]) j = ne[j];
      if (s[i] == s[j + 1]) j++;
      ne[i] = j;
    }
  };
  while (scanf("%d", &n), n) {
    printf("Test case #%d\n", ++cs);
    scanf("%s", s + 1);
    build_ne();
    for (int i = 2; i <= n; i++)
      if (ne[i] && i % (i - ne[i]) == 0)
        printf("%d %d\n", i, i / (i - ne[i]));
    putchar('\n');
  }
}