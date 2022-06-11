#include <iostream>
#include <list>
using namespace std;
using lit = list<int>::iterator;

const int N = 1e5 + 10;
int n, m;
list<int> a;
lit it[N];

int main() {
  a.push_front(1);
  it[1] = a.begin();

  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    int k, p;
    scanf("%d%d", &k, &p);
    if (!p) it[i] = a.insert(it[k], i);
    else {
      auto ne = next(it[k]);
      it[i] = a.insert(ne, i);
    }
  }

  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    if (it[x] != a.end()) {
      a.erase(it[x]);
      it[x] = a.end();
    }
  }

  for (auto x: a) printf("%d ", x);
}