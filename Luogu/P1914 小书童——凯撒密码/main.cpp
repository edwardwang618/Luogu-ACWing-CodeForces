#include <iostream>
using namespace std;

int main() {
    int x;
    string s;
    cin >> x >> s;

    for (char& ch : s)
        if (ch + x <= 'z') ch += x;
        else ch += x - 26;

    cout << s << endl;

    return 0;
}