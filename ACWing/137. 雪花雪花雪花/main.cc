#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5 + 10;
int n;
int snows[N][6], idx[N];

bool cmp_arr(int a[], int b[]) {
  for (int i = 0; i < 6; i++)
    if (a[i] != b[i]) return a[i] < b[i];
  return true;
}

bool cmp(int a, int b) {
  return cmp_arr(snows[a], snows[b]);
}

void get_min(int a[]) {
  int b[12];
  for (int i = 0; i < 12; i++) b[i] = a[i % 6];

  int i = 0, j = 1, k;
  while (i < 6 && j < 6) {
    for (k = 0; k < 6 && b[i + k] == b[j + k]; k++);
    if (k == 6) break;
    if (b[i + k] > b[j + k]) i += k + 1;
    else j += k + 1;
    if (i == j) j++;
  }

  k = min(i, j);
  for (int i = 0; i < 6; i++) a[i] = b[i + k];
}

int main() {
  scanf("%d", &n);
  int snow[6], isnow[6];
  for (int i = 0; i < n; i++) {
    for (int j = 0, k = 5; j < 6; j++, k--) {
      scanf("%d", &snow[j]);
      isnow[k] = snow[j];
    }
    get_min(snow);
    get_min(isnow);

    if (cmp_arr(snow, isnow)) memcpy(snows[i], snow, sizeof snow);
    else memcpy(snows[i], isnow, sizeof isnow);

    idx[i] = i;
  }
  
  sort(idx, idx + n, cmp);

  bool flag = false;
  for (int i = 1; i < n; i++)
    if (cmp(idx[i - 1], idx[i]) && cmp(idx[i], idx[i - 1])) {
      flag = true;
      break;
    }
  
  if (flag) puts("Twin snowflakes found.");
  else puts("No two snowflakes are alike.");
}