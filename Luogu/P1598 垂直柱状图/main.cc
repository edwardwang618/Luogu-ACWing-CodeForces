#include <iostream>
using namespace std;

int cnt[26];
string s;

int main() {
    for (int i = 0; i < 4; i++) {
        getline(cin, s);
        for (char ch : s)
            if ('A' <= ch && ch <= 'Z')
                cnt[ch - 'A']++;
    }

    int M = 0;
    for (int i = 0; i < 26; i++) M = max(M, cnt[i]);

    for (int i = M; i; i--) {
        s.clear();
        for (int x : cnt) {
            if (x >= i) s += '*';
            else s += ' ';

            s += ' ';
        }

        s.pop_back();
        cout << s << endl;
    }

    s.clear();
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        s += ch;
        s += ' ';
    }

    s.pop_back();
    cout << s;

    return 0;
}