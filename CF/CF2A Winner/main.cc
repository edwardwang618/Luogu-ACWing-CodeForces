#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 1010;
int n, maxv;
string maxp;
unordered_map<string, int> mp, mmp;
int x[N];
string s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    cin >> s[i] >> x[i];
    mp[s[i]] += x[i];
  }

  for (int i = 1; i <= n; i++) 
    maxv = max(maxv, mp[s[i]]);

  for (int i = 1; i <= n; i++) {
    mmp[s[i]] += x[i];
    if (mp[s[i]] == maxv && mmp[s[i]] >= maxv) {
      maxp = s[i];
      break;
    }
  }
  
  cout << maxp << endl;
} 