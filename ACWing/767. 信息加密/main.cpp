#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if ('a' <= s[i] && s[i] <= 'z' || 'A' <= s[i] && s[i] <= 'Z') {
            if (s[i] == 'z' || s[i] == 'Z') s[i] -= 25;
            else s[i]++;
        }

        printf("%c", s[i]);
    }

    return 0;
}