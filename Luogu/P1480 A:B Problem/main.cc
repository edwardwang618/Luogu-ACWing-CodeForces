#include <iostream>
using namespace std;

string a, res;
long b;

int main() {
  cin >> a >> b;
  long t = 0;
  for (int i = 0; i < a.size(); i++) {
    res.push_back((t * 10 + a[i] - '0') / b + '0');
    t = (t * 10 + a[i] - '0') % b;
  }

  int i = 0;
  while (i + 1 < res.size() && res[i] == '0') i++;
  cout << res.substr(i) << endl;
}