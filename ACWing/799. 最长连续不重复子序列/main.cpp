#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 100010;
int n, a[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int res = 0;
  unordered_map<int, int> map;
  for (int i = 0, j = 0; i < n; i++) {
    map[a[i]]++;
    while (j < i && map[a[i]] > 1) map[a[j++]]--;
    res = max(res, i - j + 1);
  }

  cout << res << endl;
}