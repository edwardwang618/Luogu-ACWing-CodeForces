#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    char ch;
    cin >> ch;

    for (int i = 0; i < s.size(); i++) 
        if (s[i] == ch) printf("#");
        else printf("%c", s[i]);

    return 0;
}