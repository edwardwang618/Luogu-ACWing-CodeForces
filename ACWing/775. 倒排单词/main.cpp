#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    for (int i = 0, j = 0; i <= s.size(); i++) 
        if (i == s.size() || s[i] == ' ') {
            reverse(s.begin() + j, s.begin() + i);
            j = i + 1;
        }

    reverse(s.begin(), s.end());
    cout << s << endl;
    return 0;
}