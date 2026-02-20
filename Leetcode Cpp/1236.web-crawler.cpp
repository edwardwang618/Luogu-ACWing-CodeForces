/*
 * @lc app=leetcode id=1236 lang=cpp
 *
 * [1236] Web Crawler
 */

// @lc code=start
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
  vector<string> crawl(const string &start, HtmlParser parser) {
    auto getDomain = [&](const string &url) {
      constexpr int start = 7;
      int end = url.find('/', start);
      if (end == string::npos)
        return url.substr(start);
      return url.substr(start, end - start);
    };

    string domain = getDomain(start);
    unordered_set<string> vis{start};
    vector<string> res;
    auto dfs = [&](this auto &&dfs, const string &url) -> void {
      res.push_back(url);
      for (auto &ne : parser.getUrls(url))
        if (getDomain(ne) == domain && vis.insert(ne).second)
          dfs(ne);
    };
    dfs(start);
    return res;
  }
};
// @lc code=end
