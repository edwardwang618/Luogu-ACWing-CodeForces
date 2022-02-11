#include <iostream>
#include <cstring>
using namespace std;

string s;

int main() {
    cin >> s;

    string o = "aeiouy";
    for (char &ch : s) {
        ch = tolower(ch);
        if (o.find(ch) == -1) cout << '.' << ch;
    }

    return 0;
}