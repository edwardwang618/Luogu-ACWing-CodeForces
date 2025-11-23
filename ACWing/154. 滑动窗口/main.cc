#include <iostream>
#include <deque>
#include <vector>
using namespace std;

const int N = 1e6 + 10;
int a[N];
int n, k;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  auto f = [&](auto cmp) {
    deque<int> dq;
    vector<int> res;
    
    for (int i = 1; i <= n; i++) {
      while (dq.size() && cmp(a[dq.back()], a[i])) dq.pop_back();
      dq.push_back(i);
      if (dq.front() <= i - k) dq.pop_front();
      if (i >= k) res.push_back(a[dq.front()]);
    }
    
    return res;
  };
  
  vector<int> v2 = f([](int a, int b) { return a >= b; });
  vector<int> v1 = f([](int a, int b) { return a <= b; });
  
  for (int x : v2) printf("%d ", x);
  puts("");
  for (int x : v1) printf("%d ", x);
}