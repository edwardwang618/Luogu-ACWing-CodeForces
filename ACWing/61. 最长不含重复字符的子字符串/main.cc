#include <cstring>
using namespace std;

class Solution {
public:
  int longestSubstringWithoutDuplication(string s) {
    int res = 0, c[26], cnt = 0;
    memset(c, 0, sizeof c);
    for (int i = 0, j = 0; i < s.size(); i++) {
      c[s[i] - 'a']++;
      if (c[s[i] - 'a'] == 1) cnt++;
      while (cnt < i - j + 1) {
        c[s[j] - 'a']--;
        if (!c[s[j++] - 'a']) cnt--;
      }
      res = max(res, i - j + 1);
    }

    return res;
  }
};