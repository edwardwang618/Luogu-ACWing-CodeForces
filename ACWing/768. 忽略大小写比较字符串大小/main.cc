#include <iostream>
using namespace std;

int main() {
    string s, t;
    getline(cin, s);
    getline(cin, t);
    bool flag = false;
    for (int i = 0; i < s.size() && i < t.size(); i++) {
        char c1 = tolower(s[i]), c2 = tolower(t[i]);
        if (c1 != c2) {
            puts(c1 < c2 ? "<" : ">");
            flag = true;
            break;
        }
    }

    if (!flag)
        if (s.size() != t.size()) puts(s.size() < t.size() ? "<" : ">");
        else puts("=");

    return 0;
}