#include <iostream>
#include <string>
using namespace std;

string w, s;

int main() {
  getline(cin, w);
  getline(cin, s);
  int idx = -1, cnt = 0;
  for (int i = 0, j; i < s.size(); i++) {
    if (s[i] == ' ') continue;
    j = i;
    while (j < s.size() && s[j] != ' ') j++;
    if (j - i == w.size()) {
      int k;
      for (k = i; k < j; k++)
        if (tolower(s[k]) != tolower(w[k - i])) break;
      if (k == j) {
        if (!~idx) idx = i;
        cnt++;
      }
    }
    i = j;
  }

  if (!~idx)
    puts("-1");
  else
    printf("%d %d\n", cnt, idx);
}