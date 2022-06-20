#include <iostream>
#include <cstring>
using namespace std;

const int N = 1000010;
int n, ne[N], maxl;
char s[N];

void build_ne() {
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && s[i] != s[j + 1]) j = ne[j];
    if (s[i] == s[j + 1]) j++;
    ne[i] = j;
    if (i < n) maxl = max(maxl, ne[i]);
  }
}

int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);

  build_ne();
  int len = ne[n];
  if (!len) puts("Just a legend");
  else {
    while (len > maxl) len = ne[len];
    if (!len) puts("Just a legend");
    else for (int i = 1; i <= len; i++) putchar(s[i]);
  }
}