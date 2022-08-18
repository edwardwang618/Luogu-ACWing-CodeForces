#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int cnt[26] = {0};
    for (char ch : s) cnt[ch - 'a']++;
    bool found = false;
    for (char ch : s) 
        if (cnt[ch - 'a'] == 1) {
            found = true, printf("%c\n", ch); 
            break;
        }

    if (!found) puts("no");
    return 0;
}