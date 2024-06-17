#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int merge_sort(vector<int>& a, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l >> 1);
    int res = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1, k = l;
    static vector<int> tmp(a.size());
    while (i <= mid && j <= r)
      if (a[i] <= a[j])
        tmp[k++] = a[i++];
      else {
        res += mid - i + 1;
        tmp[k++] = a[j++];
      }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= r) tmp[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = tmp[i];
    return res;
  }

  int inversePairs(vector<int>& a) {
    int n = a.size();
    return merge_sort(a, 0, n - 1);
  }
};
