#include <iostream>
using namespace std;

int main() {
    double k;
    cin >> k;
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) if (s[i] == t[i]) cnt++;

    if ((double) cnt / s.size() >= k) puts("yes");
    else puts("no");

    return 0;
}