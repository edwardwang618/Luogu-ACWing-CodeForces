// Forward declaration of compare API.
// bool compare(int a, int b);
// return bool means whether a is less than b.
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> specialSort(int N) {
    vector<int> v;
    for (int i = 1; i <= N; i++) v.push_back(i);
    merge_sort(v, 0, v.size() - 1);
    return v;
  }

  void merge_sort(vector<int>& v, int l, int r) {
    if (l >= r) return;
    static vector<int> tmp(v.size());
    int mid = l + r >> 1;
    merge_sort(v, l, mid);
    merge_sort(v, mid + 1, r);
    int i = l, j = mid + 1, idx = i;
    while (i <= mid && j <= r)
      if (compare(v[i], v[j]))
        tmp[idx++] = v[i++];
      else
        tmp[idx++] = v[j++];

    while (i <= mid) tmp[idx++] = v[i++];
    while (j <= r) tmp[idx++] = v[j++];
    for (int i = l; i <= r; i++) v[i] = tmp[i];
  }
};