#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string mid, post;
unordered_map<char, int> mp;

void dfs(int ml, int mr, int pl, int pr) {
  if (ml > mr) return;
  putchar(post[pr]);
  int root_idx = mp[post[pr]], lsz = root_idx - ml;
  dfs(ml, root_idx - 1, pl, pl + lsz - 1);
  dfs(root_idx + 1, mr, pl + lsz, pr - 1);
}

int main() {
  cin >> mid;
  cin >> post;
  int n = mid.size();
  for (int i = 0; i < n; i++) mp[mid[i]] = i;
  dfs(0, n - 1, 0, n - 1);
  puts("");
}