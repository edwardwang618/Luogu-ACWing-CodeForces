#include <iostream>
using namespace std;

int n;
int res = 2e9;

int main() {
  cin >> n;
  for (int i = 0; i < 3; i++) {
    int cnt, price;
    cin >> cnt >> price;
    res = min(res, (n + cnt - 1) / cnt * price);
  }
  
  printf("%d\n", res);
}