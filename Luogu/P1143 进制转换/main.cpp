#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

int main() {
    string s;
    long x = 0;
    cin >> n >> s >> m;
    
    for (int i = 0; i < s.size(); i++) {
        x *= n;
        if (isdigit(s[i])) x += s[i] - '0';
        else x += s[i] - 'A' + 10;
    }

    s.clear();
    while (x) {
        int c = x % m;
        if (c >= 10) s += 'A' + c - 10;
        else s += to_string(c);
        x /= m;
    }

    if (!s.size()) printf("0\n");

    reverse(s.begin(), s.end());
    cout << s << endl;

    return 0;
}