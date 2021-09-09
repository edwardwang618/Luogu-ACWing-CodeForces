#include <iostream>
using namespace std;

string w, s;

int main() {
    getline(cin, w);
    getline(cin, s);
    for (char &ch : w) ch = tolower(ch);
    for (char &ch : s) ch = tolower(ch);

    int cnt = 0, pos = -1;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while (j < s.size() && s[j] != ' ') j++;
        if (s.substr(i, j - i) == w) {
            cnt++;
            if (pos == -1) pos = i;
        }

        i = j;
    }

    if (pos != -1) printf("%d %d\n", cnt, pos);
    else puts("-1");

    return 0;
}