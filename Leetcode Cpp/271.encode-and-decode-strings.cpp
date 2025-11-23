/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 */

// @lc code=start
class Codec {
 public:
  // Encodes a list of strings to a single string.
  string encode(vector<string>& strs) {
    string res;
    for (auto& s : strs) {
      for (char ch : s) {
        if (ch == '$') res += '$';
        res += ch;
      }
      res += " $ ";
    }

    return res;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> res;
    for (int i = 0, j = 0; i < s.size(); i++)
      if (s.substr(i, 3) == " $ ") {
        res.push_back(s.substr(j, i - j));
        i += 2;
        j = i + 1;
      }

    for (auto& s : res) {
      string t;
      for (int i = 0; i < s.size(); i++)
        if (s[i] != '$') t += s[i];
        else {
          int j = i;
          while (j < s.size() && s[j] == '$') j++;
          t += string((j - i) / 2, '$');
          i = j - 1;
        }

      s = t;
    }

    return res;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
// @lc code=end
