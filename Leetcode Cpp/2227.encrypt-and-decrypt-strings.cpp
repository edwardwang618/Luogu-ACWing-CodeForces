/*
 * @lc app=leetcode id=2227 lang=cpp
 *
 * [2227] Encrypt and Decrypt Strings
 */

// @lc code=start
class Encrypter {
public:
  unordered_map<char, string> mp;
  unordered_map<string, int> cnt;

  Encrypter(vector<char> &ks, vector<string> &vals, vector<string> &dict) {
    for (int i = 0; i < ks.size(); i++)
      mp[ks[i]] = vals[i];
    for (auto &s : dict) {
      string enc = encrypt(s);
      if (enc.size())
        cnt[enc]++;
    }
  }

  string encrypt(const string &s) {
    string res;
    for (char ch : s) {
      if (auto it = mp.find(ch); it != mp.end())
        res += it->second;
      else
        return "";
    }
    return res;
  }

  int decrypt(const string &s) {
    auto it = cnt.find(s);
    return it != cnt.end() ? it->second : 0;
  }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
// @lc code=end
