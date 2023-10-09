#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 100010;
int n, a[N];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);

  int res = 0;
  unordered_set<int> st;
  for (int i = 0, j = 0; i < n; i++) {
    while (st.count(a[i])) st.erase(a[j++]);
    st.insert(a[i]);
    res = max(res, i - j + 1);
  }

  cout << res << endl;
}