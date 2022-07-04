#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n / i; i++)
    if (n % i == 0) {
      printf("%d\n", n / i);
      break;
    }
  
}