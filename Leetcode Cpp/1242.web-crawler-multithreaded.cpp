/*
 * @lc app=leetcode id=1242 lang=cpp
 *
 * [1242] Web Crawler Multithreaded
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
  vector<string> res;
  unordered_set<string> vis;
  mutex mu;

  void crawlUtil(string& startUrl, HtmlParser& parser, string& host) {
    vector<string> v = parser.getUrls(startUrl);
    vector<thread*> ts(v.size(), nullptr);

    for (int i = 0; i < v.size(); i++) {
      {
        unique_lock<mutex> ul(mu);
        if (vis.count(v[i]) || v[i].find(host)) continue;
        vis.insert(v[i]);
        res.push_back(v[i]);
      }

      ts[i] = new thread(&Solution::crawlUtil, this, ref(v[i]), ref(parser),
                         ref(host));
    }

    for (auto* t : ts)
      if (t) t->join();
  }

  vector<string> crawl(string startUrl, HtmlParser parser) {
    res.push_back(startUrl);
    vis.insert(startUrl);

    string host = "http://";
    for (int i = host.size(); i < startUrl.size(); i++)
      if (startUrl[i] != '/')
        host += startUrl[i];
      else
        break;

    thread t(&Solution::crawlUtil, this, ref(startUrl), ref(parser), ref(host));
    t.join();
    return res;
  }
};
// @lc code=end
