#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int max = 0;
        char ch;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            while (j < s.size() && s[j] == s[i]) {
                j++;
            }

            if (j - i > max) {
                max = j - i;
                ch = s[i];
            }

            i = j - 1;
        }

        cout << ch << ' ' << max << endl;
    }
}