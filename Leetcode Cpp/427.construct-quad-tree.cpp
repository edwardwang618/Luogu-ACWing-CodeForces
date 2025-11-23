/*
 * @lc app=leetcode id=427 lang=cpp
 *
 * [427] Construct Quad Tree
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/

class Solution {
 public:
  vector<vector<int>> pre;
  Node* construct(vector<vector<int>>& g) {
    int n = g.size();
    pre = vector<vector<int>>(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        pre[i + 1][j + 1] = g[i][j] + pre[i + 1][j] + pre[i][j + 1] - pre[i][j];
    return dfs(0, 0, n - 1, n - 1);
  }

  Node* dfs(int x1, int y1, int x2, int y2) {
    int sum =
        pre[x2 + 1][y2 + 1] - pre[x2 + 1][y1] - pre[x1][y2 + 1] + pre[x1][y1];
    int n = x2 - x1 + 1;
    if (!sum || sum == n * n)
      return new Node(!!sum, true, nullptr, nullptr, nullptr, nullptr);
    Node* topLeft = dfs(x1, y1, (x1 + x2) / 2, (y1 + y2) / 2);
    Node* topRight = dfs(x1, (y1 + y2) / 2 + 1, (x1 + x2) / 2, y2);
    Node* bottomLeft = dfs((x1 + x2) / 2 + 1, y1, x2, (y1 + y2) / 2);
    Node* bottomRight = dfs((x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1, x2, y2);
    return new Node(1, false, topLeft, topRight, bottomLeft, bottomRight);
  }
};
// @lc code=end
