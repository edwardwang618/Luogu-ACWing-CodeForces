#include <iostream>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;
unordered_map<int, int> mp;

void divide(int n) {
  for (int i = 2; i <= n / i; i++) {
    if (n % i == 0)
      while (n % i == 0) {
        mp[i]++;
        n /= i;
      }
  }

  if (n >= 2) mp[n]++;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;

    divide(x);
  }

  long res = 1;
  for (auto p : mp) res = res * (p.second + 1) % MOD;
  printf("%ld\n", res);
}