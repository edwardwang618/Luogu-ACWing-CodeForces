#include <iostream>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            while (i < s.size() && s[i] == ' ') i++;
            i--;
        }

        s[j++] = s[i];
    }

    for (int i = 0; i < j; i++) printf("%c", s[i]);

    return 0;
}