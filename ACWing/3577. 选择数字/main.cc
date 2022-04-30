#include <iostream>
using namespace std;

int n, m;

int main() {
  int t = 0;
  scanf("%d", &n);
  while (n--) {
    int x;
    scanf("%d", &x);
    t = max(t, x);
  }

  int s = 0;
  scanf("%d", &m);
  while (m--) {
    int x;
    scanf("%d", &x);
    s = max(s, x);
  }
  
  cout << t << ' ' << s << endl;
}