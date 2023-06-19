#include <vector>
using namespace std;

class Solution {
 public:
  bool verifySequenceOfBST(vector<int> v) { return dfs(0, v.size() - 1, v); }

  bool dfs(int l, int r, vector<int>& v) {
    if (l >= r) return true;
    int root = v[r], k = l;
    while (k < r && v[k] < root) k++;
    for (int i = k; i < r; i++)
      if (v[i] < root) return false;

    return dfs(l, k - 1, v) && dfs(k, r - 1, v);
  }
};