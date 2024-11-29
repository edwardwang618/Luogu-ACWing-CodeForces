#include <deque>
#include <iostream>
using namespace std;

const int N = 1000010;
int a[N];

int main() {
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) cin >> a[i];

  deque<int> dq;

  for (int i = 0; i < n; i++) {
    while (!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();
    if (i >= k - 1) cout << a[dq.front()] << " ";
  }

  cout << endl;
  dq.clear();
  for (int i = 0; i < n; i++) {
    while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
    dq.push_back(i);
    if (dq.front() <= i - k) dq.pop_front();
    if (i >= k - 1) cout << a[dq.front()] << " ";
  }
}