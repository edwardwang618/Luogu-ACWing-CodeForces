#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
const int N = 6;
string a[N], b[N];
int n;

bool one_step(queue<string> &qa, unordered_set<string> &sa, unordered_set<string> &sb, string a[], string b[]) {
  for (int sz = qa.size(); sz; sz--) {
    string s = qa.front();
    qa.pop();
    for (int i = 0; i < s.size(); i++)
      for (int j = 0; j < n; j++)
        if (i + a[j].size() <= s.size() && s.substr(i, a[j].size()) == a[j]) {
          string ne = s.substr(0, i) + b[j] + s.substr(i + a[j].size());
          if (sb.count(ne)) return true;
          if (sa.count(ne)) continue;
          sa.insert(ne);
          qa.push(ne);
        }
  }

  return false;
}

int bfs(string &A, string &B) {
  if (A == B) return 0;

  queue<string> qa, qb;
  unordered_set<string> visa, visb;
  qa.push(A);
  visa.insert(A);
  qb.push(B);
  visb.insert(B);

  int step = 0;
  while (qa.size() && qb.size()) {
    step++;
    if (step > 10) break;
    if (qa.size() <= qb.size()) {
      if (one_step(qa, visa, visb, a, b)) return step;
    } else if (one_step(qb, visb, visa, b, a)) return step;
  }

  return 11;
}

int main() {
  string A, B;
  cin >> A >> B;
  while (cin >> a[n] >> b[n]) {
    n++;
    if (n == 6) break;
  }

  int step = bfs(A, B);
  if (step > 10) puts("NO ANSWER!");
  else printf("%d\n", step);

  return 0;
}