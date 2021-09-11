#include <iostream>
#include <algorithm>
using namespace std;

string reverse(string s) {
    if (!s.size()) {
        s = "0";
        return s;
    }

    reverse(s.begin(), s.end());
    int i = 0;
    while (i < s.size() - 1 && s[i] == '0') i++;
    return s.substr(i);
}

string deleteTail(string s) {
    if (!s.size()) {
        s = "0";
        return s;
    }

    while (s.size() > 1 && s.back() == '0') s.pop_back();
    return s;
}

int main() {
    string s;
    cin >> s;
    if (s.back() == '%') {
        cout << reverse(s.substr(0, s.size() - 1)) << "%" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        string left, right;

        if (s[i] == '/') {
            left = s.substr(0, i);
            right = s.substr(i + 1);
            cout << reverse(left) << "/" << reverse(right) << endl;
            return 0;
        }

        if (s[i] == '.') {
            left = s.substr(0, i);
            right = s.substr(i + 1);
            cout << reverse(left) << "." << deleteTail(reverse(right)) << endl;
            return 0;
        }
    }

    cout << reverse(s) << endl;
    return 0;
}