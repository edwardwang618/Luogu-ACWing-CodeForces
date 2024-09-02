#include <iostream>
using namespace std;

const int N = 30;
int g[N][N];
int t[4][4];

bool check(int row, int col) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i + row >= 15 && t[i][j] == 1) return true;
      if (g[i + row][j + col] && t[i][j]) return true;
    }
  }
  return false;
}

int main() {
  for (int i = 0; i < 15; i++)
    for (int j = 0; j < 10; j++) scanf("%d", &g[i][j]);
  for (int i = 0; i < 4; i++)
    for (int j = 0; j < 4; j++) scanf("%d", &t[i][j]);

  int col;
  scanf("%d", &col);
  col--;
  int k = 1;
  while (k < 15) {
    if (check(k, col)) break;
    k++;
  }
  k--;
  for (int i = k; i < k + 4; i++)
    for (int j = col; j < col + 4; j++)
      g[i][j] = t[i - k][j - col] == 0 ? g[i][j] : 1;

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 10; j++) printf("%d ", g[i][j]);
    cout << endl;
  }
}
