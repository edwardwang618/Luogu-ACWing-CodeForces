#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s, p;
int n, m;
vector<int> res;

void buildNext(string p, int ne[]) {
  ne[0] = -1;
  for (int i = 0, j = -1; i < m - 1;)
    if (j < 0 || p[j] == p[i])
      ne[++i] = ++j;
    else
      j = ne[j];
}

void kmp(string s, string p) {
  int ne[m];
  buildNext(p, ne);
  for (int i = 0, j = 0; i < n;) {
    if (j == -1 || s[i] == p[j]) {
      i++, j++;
      if (j == m) {
        cout << i - j << " ";
        i--;
        j = ne[j - 1];
      }
    } else
      j = ne[j];
  }
}

int main() {
  cin >> m;
  cin >> p;
  cin >> n;
  cin >> s;

  kmp(s, p);
}