#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_map<string, int> mp, mp1;
unordered_set<string> st;
vector<string> vs;
int n, q;

int main() {
  scanf("%d", &n);
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vs.push_back(s);
    st.clear();
    for (int j = 0; j < s.size(); j++)
      for (int k = j; k < s.size(); k++) {
        auto t = s.substr(j, k - j + 1);
        if (!st.count(t)) {
          st.insert(t);
          mp1[t] = i;
          mp[t]++;
        }
      }
  }
  scanf("%d", &q);
  while (q--) {
    cin >> s;
    if (!mp[s])
      puts("0 -");
    else
      cout << mp[s] << " " << vs[mp1[s]] << endl;
  }
}